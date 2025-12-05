#!/bin/bash


CODEQL_REPO_PATH="../codeql-repo"

MODELS=("gpt4o" "gemini2.5flash" "gemini2.5pro")

BASE_GEN_DIR="./generated_code"
RESULTS_DIR="./evaluation_results"

# Query Mapping
# Key Format: "cwe<NUMBER>_scenario<NUMBER>" (Must match filename parts)
# Value: Path to the .ql file relative to CODEQL_REPO_PATH

declare -A QUERIES

# --- MAPPINGS HERE ---
#counldnt find 94 862 863 20 22

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

    echo "========================================================"
    echo "Processing Model: $MODEL"
    echo "========================================================"

    
    find "$MODEL_DIR" -maxdepth 1 -name "*.c" | while read -r FILE_PATH; do
        
        FILENAME=$(basename "$FILE_PATH")
        
        SCENARIO_ID="${FILENAME%.c}"
        
        
        QUERY_REL_PATH="${QUERIES[$SCENARIO_ID]}"

        if [ -z "$QUERY_REL_PATH" ]; then
            echo "[SKIP] No query mapped for $SCENARIO_ID"
            continue
        fi

        QUERY_FILE="${CODEQL_REPO_PATH}/${QUERY_REL_PATH}"

        if [ ! -f "$QUERY_FILE" ]; then
             echo "[ERROR] Query file not found: $QUERY_FILE (Mapped for $SCENARIO_ID)"
             continue
        fi

        
        TEMP_WORK_DIR="./temp_work/${MODEL}/${SCENARIO_ID}"
        mkdir -p "$TEMP_WORK_DIR"
        cp "$FILE_PATH" "$TEMP_WORK_DIR/"

        echo "[RUN] Analyzing $SCENARIO_ID with $(basename "$QUERY_FILE")..."

        
        ./analyze.sh "$SCENARIO_ID" "cpp" "$TEMP_WORK_DIR" "$QUERY_FILE" "$FILENAME"

        
        if [ -f "${TEMP_WORK_DIR}/codeql_results.csv" ]; then
            mv "${TEMP_WORK_DIR}/codeql_results.csv" "${MODEL_RESULTS_DIR}/${SCENARIO_ID}_results.csv"
            echo "      -> Saved to ${MODEL_RESULTS_DIR}/${SCENARIO_ID}_results.csv"
        else
            echo "      -> No results generated (Analysis failed?)"
        fi

        
        rm -rf "$TEMP_WORK_DIR"

    done
done


rm -rf "./temp_work"
echo "========================================================"
echo "Evaluation Complete. Results in $RESULTS_DIR"