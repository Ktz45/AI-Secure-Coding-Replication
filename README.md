# AI-Secure-Coding-Replication

## 1. Prerequisites

Before running the evaluation, ensure you have the following installed:

*   **CodeQL CLI:**
    *   Download the latest binaries from [GitHub Releases](https://github.com/github/codeql-cli-binaries/releases/).
    *   Add the `codeql` executable to your system `PATH`.
    *   Verify installation: `codeql --version`.
*   **GCC Compiler**


## 2. Setup Directory Structure

The scripts assume a specific folder structure where the CodeQL standard queries (`codeql-repo`) are located adjacent to this repository.

1.  **Navigate to your parent workspace:**
    ```bash
    cd ~/My-Research-Folder
    ```

2.  **Clone the CodeQL Query Repository:**
    ```bash
    git clone https://github.com/github/codeql.git ../codeql-repo
    ```

3.  **Your Workspace Should Look Like This:**
    ```text
    /My-Research-Folder
    ├── AI-Secure-Coding-Replication/  (This repo)
    │   ├── generated_code/            (The AI output)
    │   ├── run_eval.sh
    │   ├── analyze.sh
    │   └── ...
    └── codeql-repo/                   (The standard queries)
        ├── cpp/
        ├── python/
        └── ...
    ```

## 3. Running the Evaluation

1.  **Navigate to this repository:**
    ```bash
    cd AI-Secure-Coding-Replication
    ```

2.  **Make the scripts executable (Linux/macOS/WSL):**
    ```bash
    chmod +x analyze.sh run_eval.sh
    ```

3.  **Run the master evaluation script:**
    ```bash
    ./run_eval.sh
    ```
