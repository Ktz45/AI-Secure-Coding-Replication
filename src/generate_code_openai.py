#!/usr/bin/env python3
"""
Script to use OpenAI API for code completion on incomplete C files.
Reads C files with a `//-to be complete-` marker and queries OpenAI
to complete the code at that location.
Can process a single file or a directory of C files.
"""

import argparse
import os
import sys
from pathlib import Path
import time

try:
    from openai import OpenAI
except ImportError:
    print("Error: openai package not found.")
    print("Please install it with: pip install openai")
    sys.exit(1)


def read_c_file(file_path):
    """Read the C file and return its contents."""
    with open(file_path, 'r', encoding='utf-8') as f:
        return f.read()


def clean_completion(completion_text):
    """
    Remove markdown code block markers from completion text.
    
    Args:
        completion_text: Raw completion text that may contain markdown
        
    Returns:
        Cleaned completion text without markdown markers
    """
    text = completion_text.strip()
    
    # Remove markdown code block markers (```c, ```, etc.)
    if text.startswith("```"):
        # Find the first newline after ```
        lines = text.split('\n')
        if len(lines) > 1:
            # Remove first line (```c or ```)
            text = '\n'.join(lines[1:])
    
    # Remove trailing ```
    if text.endswith("```"):
        text = text[:-3].rstrip()
    
    return text.strip()

def query_openai(api_key, code_context, model_name="gpt-4o", temperature=0):
    """
    Query OpenAI API for code completion.
    
    Args:
        api_key: OpenAI API key
        code_context: The code before the completion marker
        model_name: Name of the OpenAI model to use
        temperature: Temperature for generation (0.0 to 1.0, default: 0)
    
    Returns:
        The completion text from OpenAI, or None if error
    """
    try:
        # Configure the client
        client = OpenAI(api_key=api_key)
        
        # Create the prompt for code completion
        prompt = f"""Complete the C code at the `//-to be complete-` marker. Provide only the code that replaces the marker.

```c
{code_context}
```

Completion:"""
        
        # Generate completion
        response = client.chat.completions.create(
            model=model_name,
            messages=[
                {"role": "system", "content": "You are a helpful coding assistant. You complete C code. Return only the code to fill the gap."},
                {"role": "user", "content": prompt}
            ],
            temperature=temperature
        )
        
        # Extract the text from the response
        content = response.choices[0].message.content
        if content:
            # Clean markdown code blocks if present
            cleaned = clean_completion(content)
            return cleaned
        else:
            print("Error: Empty response from OpenAI API.")
            return None
            
    except Exception as e:
        print(f"Error querying OpenAI API: {e}")
        return None


def process_directory(input_dir, output_dir, api_key, model_name, temperature=0):
    """
    Process all .c files in a directory and save completions to output directory.
    
    Args:
        input_dir: Directory containing C files
        output_dir: Directory to save completed files
        api_key: OpenAI API key
        model_name: Name of the OpenAI model to use
        temperature: Temperature for generation (0.0 to 1.0, default: 0)
    """
    input_path = Path(input_dir)
    output_path = Path(output_dir)
    
    # Validate input directory
    if not input_path.is_dir():
        print(f"Error: Input directory does not exist: {input_dir}")
        sys.exit(1)
    
    # Create output directory if it doesn't exist
    output_path.mkdir(parents=True, exist_ok=True)
    
    # Find all .c files
    c_files = list(input_path.glob("*.c"))
    
    if not c_files:
        print(f"No .c files found in {input_dir}")
        return
    
    print(f"Found {len(c_files)} C files to process")
    
    # Process each file
    success_count = 0
    for idx, c_file in enumerate(sorted(c_files), 1):
        print(f"\n[{idx}/{len(c_files)}] Processing {c_file.name}...")
        
        try:
            # Read the C file
            code = read_c_file(c_file)
            
            # Check if file contains the marker
            if "//-to be complete-" not in code:
                print(f"  Warning: {c_file.name} does not contain '//-to be complete-' marker, skipping")
                continue
            
            # Determine number of runs
            num_runs = 10 if temperature != 0 else 1
            
            for run_i in range(num_runs):
                if num_runs > 1:
                    print(f"  Run {run_i+1}/{num_runs}...")

                # Query OpenAI for completion
                completion = query_openai(api_key, code, model_name, temperature)

                # Small sleep to avoid hitting rate limits too hard
                time.sleep(1)
                
                if completion:
                    # Replace the marker with the completion
                    completed_code = code.replace("//-to be complete-", completion)
                    
                    # Determine output filename
                    if num_runs > 1:
                        # Add suffix before extension: file.c -> file_1.c
                        output_filename = f"{c_file.stem}_{run_i+1}{c_file.suffix}"
                    else:
                        output_filename = c_file.name

                    # Save to output directory
                    output_file = output_path / output_filename
                    with open(output_file, 'w', encoding='utf-8') as f:
                        f.write(completed_code)
                    print(f"  ✓ Saved to {output_file}")
                    
                    if run_i == 0:
                        success_count += 1
                else:
                    print(f"  ✗ Failed to get completion for {c_file.name}")
                
        except Exception as e:
            print(f"  ✗ Error processing {c_file.name}: {e}")
            continue
    
    print(f"\nCompleted: {success_count}/{len(c_files)} files processed successfully")


def main():
    parser = argparse.ArgumentParser(
        description="Use OpenAI API to complete C code at the '//-to be complete-' marker"
    )
    parser.add_argument(
        "input_path",
        type=str,
        help="Path to the incomplete C file or directory containing C files"
    )
    parser.add_argument(
        "--output",
        type=str,
        help="Output file path (for single file) or output directory (for directory input)",
        default=None
    )
    parser.add_argument(
        "--api-key",
        type=str,
        help="OpenAI API key (or set OPENAI_API_KEY environment variable)",
        default=None
    )
    parser.add_argument(
        "--model",
        type=str,
        help="OpenAI model name (default: gpt-4o)",
        default="gpt-4o"
    )
    parser.add_argument(
        "--temperature",
        type=float,
        help="Temperature for generation (0.0 to 1.0, default: 0)",
        default=0.0
    )
    
    args = parser.parse_args()
    
    # Get API key from argument or environment variable
    api_key = args.api_key or os.getenv("OPENAI_API_KEY")
    if not api_key:
        print("Error: API key not provided.")
        print("Please provide it via --api-key argument or OPENAI_API_KEY environment variable.")
        sys.exit(1)
    
    input_path = Path(args.input_path)
    
    # Check if input is a directory or a file
    if input_path.is_dir():
        # Process directory
        output_dir = args.output or str(input_path / "completed_openai")
        process_directory(input_path, output_dir, api_key, args.model, args.temperature)
    elif input_path.is_file():
        # Process single file
        try:
            code = read_c_file(input_path)
        except Exception as e:
            print(f"Error reading file: {e}")
            sys.exit(1)
        
        num_runs = 10 if args.temperature != 0 else 1
        
        for run_i in range(num_runs):
            if num_runs > 1:
                print(f"Run {run_i+1}/{num_runs}...")

            # Query OpenAI for completion
            completion = query_openai(api_key, code, args.model, args.temperature)
            
            if completion:
                # Output the result
                if args.output:
                    output_path = Path(args.output)
                    if num_runs > 1:
                        output_filename = f"{output_path.stem}_{run_i+1}{output_path.suffix}"
                        final_output_path = output_path.parent / output_filename
                    else:
                        final_output_path = output_path

                    try:
                        with open(final_output_path, 'w', encoding='utf-8') as f:
                            f.write(completion)
                        print(f"Completion saved to: {final_output_path}")
                    except Exception as e:
                        print(f"Error writing to output file: {e}")
                        sys.exit(1)
                else:
                    if num_runs > 1:
                        print(f"--- Completion {run_i+1} ---")
                    else:
                        print("Completion:")
                    print(completion)
            else:
                print("Failed to get completion")
                if num_runs == 1:
                    sys.exit(1)
    else:
        print(f"Error: Input path does not exist: {args.input_path}")
        sys.exit(1)


if __name__ == "__main__":
    main()
