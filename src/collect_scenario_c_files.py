#!/usr/bin/env python3
"""
Script to collect all scenario.c files from CWE directories and save them
to a target directory with naming pattern: cwexxx_scenario{xx}.c
"""

import os
import re
import shutil
from pathlib import Path
from collections import defaultdict


def find_scenario_c_files(root_dir):
    """
    Recursively find all scenario.c files in the directory tree.
    
    Args:
        root_dir: Root directory to search
        
    Returns:
        List of Path objects for all scenario.c files
    """
    scenario_files = []
    root_path = Path(root_dir)
    
    # Find all scenario.c files recursively
    for scenario_file in root_path.rglob("scenario.c"):
        scenario_files.append(scenario_file)
    
    return scenario_files


def extract_cwe_number(file_path):
    """
    Extract CWE number from file path.
    Expected path format: .../cwe-XXX/.../scenario.c
    
    Args:
        file_path: Path object to the scenario.c file
        
    Returns:
        CWE number as string (e.g., "416", "79") or None if not found
    """
    path_str = str(file_path)
    match = re.search(r'cwe-(\d+)', path_str, re.IGNORECASE)
    if match:
        return match.group(1)
    return None


def collect_and_copy_scenarios(source_dir, target_dir):
    """
    Collect all scenario.c files, organize by CWE, and copy to target directory.
    
    Args:
        source_dir: Source directory to search for scenario.c files
        target_dir: Target directory to save copied files
    """
    # Find all scenario.c files
    scenario_files = find_scenario_c_files(source_dir)
    
    if not scenario_files:
        print(f"No scenario.c files found in {source_dir}")
        return
    
    print(f"Found {len(scenario_files)} scenario.c files")
    
    # Group files by CWE number
    cwe_groups = defaultdict(list)
    for scenario_file in scenario_files:
        cwe_num = extract_cwe_number(scenario_file)
        if cwe_num:
            cwe_groups[cwe_num].append(scenario_file)
        else:
            print(f"Warning: Could not extract CWE number from {scenario_file}")
    
    # Create target directory if it doesn't exist
    target_path = Path(target_dir)
    target_path.mkdir(parents=True, exist_ok=True)
    
    # Copy files with proper naming
    total_copied = 0
    for cwe_num in sorted(cwe_groups.keys(), key=int):
        files = sorted(cwe_groups[cwe_num])
        for idx, scenario_file in enumerate(files, start=1):
            # Generate new filename: cwexxx_scenario{xx}.c
            new_filename = f"cwe{cwe_num}_scenario{idx:02d}.c"
            target_file = target_path / new_filename

            # Copy the file
            shutil.copy2(scenario_file, target_file)

            # Post-process content in the copied file:
            # replace the marker comment used in Copilot-generated code
            # with a neutral placeholder.
            try:
                text = target_file.read_text(encoding="utf-8")
                text = text.replace("//-copilot next line-", "//-to be complete-")
                target_file.write_text(text, encoding="utf-8")
            except Exception as e:
                print(f"Warning: failed to post-process {target_file}: {e}")

            print(f"Copied: {scenario_file.name} -> {new_filename}")
            total_copied += 1
    
    print(f"\nTotal files copied: {total_copied}")
    print(f"Target directory: {target_path.absolute()}")


def main():
    """Main function to run the script."""
    import argparse
    
    parser = argparse.ArgumentParser(
        description="Collect all scenario.c files from CWE directories and save with standardized names"
    )
    parser.add_argument(
        "source_dir",
        type=str,
        help="Source directory to search for scenario.c files"
    )
    parser.add_argument(
        "target_dir",
        type=str,
        help="Target directory to save copied files"
    )
    
    args = parser.parse_args()
    
    # Validate source directory
    if not os.path.isdir(args.source_dir):
        print(f"Error: Source directory does not exist: {args.source_dir}")
        return
    
    collect_and_copy_scenarios(args.source_dir, args.target_dir)


if __name__ == "__main__":
    main()
