## Data Files

- `codeql_analysis_summary.csv`: Results from CodeQL analysis on our generated code.
- `original_result.csv`: Results extracted from the original paper for comparison.

### Visualize Analysis
To visualize the analysis summary:

```bash
python3 visualize_analysis.py codeql_analysis_summary.csv
```

### Visualize Comparison
To compare our results with the original paper's results:

```bash
python3 visualize_comparison.py codeql_analysis_summary.csv original_result.csv
```