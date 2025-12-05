#!/bin/bash

CWE_ID="$1"
LANG="$2"
SOURCE_DIR="$3"
QUERY_PATH="$4"
FILENAME="$5" 

DB_NAME="databases/db_${CWE_ID}_${LANG}"
RESULTS_FILE="${SOURCE_DIR}/codeql_results.csv"

echo "------------------------------------------------"
echo "Creating database in ${SOURCE_DIR}..."

codeql database create --overwrite "${DB_NAME}" \
    --language="${LANG}" \
    --source-root="${SOURCE_DIR}" \
    --command="gcc -c ${FILENAME}"
echo "Running analysis with query: $(basename ${QUERY_PATH})..."
codeql database analyze "${DB_NAME}" "${QUERY_PATH}" \
    --format=csv \
    --output="${RESULTS_FILE}"

echo "Analysis complete."