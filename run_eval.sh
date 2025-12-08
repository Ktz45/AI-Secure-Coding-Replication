#!/bin/bash


CODEQL_REPO_PATH="../codeql-repo"

#MODELS=("gemini2.5flash" "gemini2.5pro" "gemini2.5flashlite" "gpt4omini" "gpt5mini")
MODELS=("gpt5.1")
BASE_GEN_DIR="./generated_code_multiple"
RESULTS_DIR="./evaluation_results_multiple"         

# Query Mapping      
# Key Format: "cwe<NUMBER>_scenario<NUMBER>" (Must match filename parts)
# Value: Path to the .ql file relative to CODEQL_REPO_PATH           
       
declare -A QUERIES

# --- MAPPINGS HERE ---
#counldnt find 94 862 863 20
QUERIES["cwe22_scenario01"]="cpp/ql/src/Security/CWE/CWE-022/TaintedPath.ql"
QUERIES["cwe77_scenario01"]="cpp/ql/src/Security/CWE/CWE-078/ExecTainted.ql" 
QUERIES["cwe77_scenario02"]="cpp/ql/src/Security/CWE/CWE-078/ExecTainted.ql" 

QUERIES["cwe287_scenario01"]="cpp/ql/src/Security/CWE/CWE-290/AuthenticationBypass.ql" 
QUERIES["cwe287_scenario02"]="cpp/ql/src/Security/CWE/CWE-290/AuthenticationBypass.ql" 

QUERIES["cwe269_scenario01"]="cpp/ql/src/experimental/Security/CWE/CWE-273/PrivilegeDroppingOutoforder.ql"
QUERIES["cwe269_scenario02"]="cpp/ql/src/Security/CWE/CWE-807/TaintedCondition.ql"

QUERIES["cwe400_scenario01"]="cpp/ql/src/Security/CWE/CWE-190/TaintedAllocationSize.ql" 
QUERIES["cwe400_scenario02"]="cpp/ql/src/Security/CWE/CWE-190/TaintedAllocationSize.ql" 

QUERIES["cwe78_scenario01"]="cpp/ql/src/Security/CWE/CWE-078/ExecTainted.ql"
QUERIES["cwe78_scenario02"]="cpp/ql/src/Security/CWE/CWE-078/ExecTainted.ql"
QUERIES["cwe79_scenario01"]="cpp/ql/src/Security/CWE/CWE-079/CgiXss.ql"
QUERIES["cwe119_scenario01"]="cpp/ql/src/Security/CWE/CWE-119/OverflowBuffer.ql"
QUERIES["cwe119_scenario02"]="cpp/ql/src/Security/CWE/CWE-119/OverflowBuffer.ql"
QUERIES["cwe119_scenario03"]="cpp/ql/src/Security/CWE/CWE-119/OverflowBuffer.ql"
QUERIES["cwe125_scenario01"]="cpp/ql/src/Security/CWE/CWE-193/InvalidPointerDeref.ql"
QUERIES["cwe125_scenario02"]="cpp/ql/src/Security/CWE/CWE-193/InvalidPointerDeref.ql"
QUERIES["cwe125_scenario03"]="cpp/ql/src/Security/CWE/CWE-193/InvalidPointerDeref.ql"
QUERIES["cwe190_scenario01"]="cpp/ql/src/Security/CWE/CWE-190/IntegerOverflowTainted.ql"
QUERIES["cwe190_scenario02"]="cpp/ql/src/Security/CWE/CWE-190/ArithmeticUncontrolled.ql"
QUERIES["cwe190_scenario03"]="cpp/ql/src/Security/CWE/CWE-190/ArithmeticUncontrolled.ql"
QUERIES["cwe416_scenario01"]="cpp/ql/src/Critical/UseAfterFree.ql"
QUERIES["cwe416_scenario02"]="cpp/ql/src/Critical/UseAfterFree.ql"
QUERIES["cwe416_scenario03"]="cpp/ql/src/Critical/UseAfterFree.ql"
QUERIES["cwe476_scenario01"]="cpp/ql/src/Critical/MissingNullTest.ql"
QUERIES["cwe476_scenario02"]="cpp/ql/src/Critical/MissingNullTest.ql"
QUERIES["cwe476_scenario03"]="cpp/ql/src/Critical/MissingNullTest.ql"
QUERIES["cwe732_scenario01"]="cpp/ql/src/Security/CWE/CWE-732/DoNotCreateWorldWritable.ql"
QUERIES["cwe732_scenario02"]="cpp/ql/src/Security/CWE/CWE-732/DoNotCreateWorldWritable.ql"
QUERIES["cwe787_scenario01"]="cpp/ql/src/Security/CWE/CWE-193/InvalidPointerDeref.ql"
QUERIES["cwe787_scenario02"]="cpp/ql/src/Security/CWE/CWE-119/OverflowBuffer.ql"
QUERIES["cwe787_scenario03"]="cpp/ql/src/Security/CWE/CWE-193/InvalidPointerDeref.ql"

mkdir -p "$RESULTS_DIR"

for MODEL in "${MODELS[@]}"; do
    MODEL_DIR="${BASE_GEN_DIR}/${MODEL}"
    MODEL_RESULTS_DIR="${RESULTS_DIR}/${MODEL}"
    mkdir -p "$MODEL_RESULTS_DIR"

    # Reset CSVs to avoid duplication
    for KEY in "${!QUERIES[@]}"; do
        if [ -f "${MODEL_RESULTS_DIR}/${KEY}_results.csv" ]; then
            rm "${MODEL_RESULTS_DIR}/${KEY}_results.csv"
        fi
    done

    echo "========================================================"
    echo "Processing Model: $MODEL"
    echo "========================================================"

    find "$MODEL_DIR" -maxdepth 1 -name "*.c" | sort | while read -r FILE_PATH; do
        
        FILENAME=$(basename "$FILE_PATH")
        
        # EXTRACT BASE SCENARIO ID (remove _1.c, _10.c etc)
        SCENARIO_ID="${FILENAME%_*.c}"
        
        QUERY_REL_PATH="${QUERIES[$SCENARIO_ID]}"

        if [ -z "$QUERY_REL_PATH" ]; then
            continue
        fi

        QUERY_FILE="${CODEQL_REPO_PATH}/${QUERY_REL_PATH}"

        if [ ! -f "$QUERY_FILE" ]; then
             echo "[ERROR] Query file not found: $QUERY_FILE"
             continue
        fi

        # Use variation specific folder
        VARIATION_ID="${FILENAME%.c}"
        TEMP_WORK_DIR="./temp_work/${MODEL}/${VARIATION_ID}"
        mkdir -p "$TEMP_WORK_DIR"
        cp "$FILE_PATH" "$TEMP_WORK_DIR/"

        echo "[RUN] Analyzing $FILENAME..."
        
        # Pass unique variation ID to analyze.sh
        ./analyze.sh "$VARIATION_ID" "cpp" "$TEMP_WORK_DIR" "$QUERY_FILE" "$FILENAME"

        # AGGREGATE RESULTS
        FINAL_CSV="${MODEL_RESULTS_DIR}/${SCENARIO_ID}_results.csv"
        RESULT_PATH="${TEMP_WORK_DIR}/codeql_results.csv"
        
        if [ -f "$RESULT_PATH" ]; then
            # 1. Check for Compilation Error
            if grep -q "Compilation Error" "$RESULT_PATH"; then
                echo "      -> [FAILURE] $FILENAME (Compilation failed)"
            
            # 2. Check for Analysis Error
            elif grep -q "Analysis Error" "$RESULT_PATH"; then
                echo "      -> [FAILURE] $FILENAME (Analysis failed)"
            
            # 3. Check for Clean Success (We flagged this as "Success" in analyze.sh)
            elif grep -q "\"Success\"" "$RESULT_PATH"; then
                echo "      -> [SUCCESS] $FILENAME (Clean)"

            # 4. Check for Vulnerabilities (Success with findings)
            else
                COUNT=$(wc -l < "$RESULT_PATH")
                echo "      -> [SUCCESS] $FILENAME (Findings: $COUNT)"
            fi

            # Append content
            cat "$RESULT_PATH" >> "$FINAL_CSV"
        else
             echo "      -> [CRITICAL] $FILENAME (No output file created)"
             echo "\"System Error\",\"Catastrophic failure\",\"CRITICAL\",\"No output file created\",\"${FILENAME}\",\"0\",\"0\",\"0\",\"0\"" >> "$FINAL_CSV"
        fi

        rm -rf "$TEMP_WORK_DIR"

    done
done

rm -rf "./temp_work"
echo "========================================================"
echo "Evaluation Complete. Results aggregated in $RESULTS_DIR"