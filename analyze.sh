#!/bin/bash

# Arguments
UNIQUE_ID="$1"
LANG="$2"
SOURCE_DIR="$3"
QUERY_PATH="$4"
FILENAME="$5"

# Create a unique DB name
DB_NAME="databases/db_${UNIQUE_ID}_${LANG}"
RESULTS_FILE="${SOURCE_DIR}/codeql_results.csv"
LOG_FILE="${SOURCE_DIR}/build.log"

# 1. Compile (Create Database)
codeql database create --overwrite "${DB_NAME}" \
    --language="${LANG}" \
    --source-root="${SOURCE_DIR}" \
    --command="gcc -c ${FILENAME}" > "$LOG_FILE" 2>&1

CMD_EXIT_CODE=$?

if [ $CMD_EXIT_CODE -ne 0 ]; then
    echo "   [ERROR] Compilation failed for ${FILENAME}"
    # Write Error Row (9 columns to match CodeQL CSV schema)
    echo "\"Compilation Error\",\"Build failed\",\"CRITICAL\",\"GCC syntax error\",\"${FILENAME}\",\"0\",\"0\",\"0\",\"0\"" > "${RESULTS_FILE}"
    exit 0
fi

# 2. Analyze
codeql database analyze "${DB_NAME}" "${QUERY_PATH}" \
    --format=csv \
    --output="${RESULTS_FILE}" > /dev/null 2>&1

ANALYSIS_EXIT_CODE=$?

if [ $ANALYSIS_EXIT_CODE -ne 0 ]; then
    echo "   [ERROR] Analysis failed for ${FILENAME}"
    # Write Analysis Error Row
    echo "\"Analysis Error\",\"Query failed\",\"CRITICAL\",\"CodeQL execution error\",\"${FILENAME}\",\"0\",\"0\",\"0\",\"0\"" > "${RESULTS_FILE}"
    exit 0
fi

# 3. Check for Empty Results (Success Case)
# If the file exists but is empty (-s checks if size > 0), it means analysis ran but found 0 bugs.
if [ ! -s "${RESULTS_FILE}" ]; then
    # Write Success Row
    echo "\"Success\",\"Analysis completed\",\"INFO\",\"No vulnerabilities found\",\"${FILENAME}\",\"0\",\"0\",\"0\",\"0\"" > "${RESULTS_FILE}"
fi