import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import os
import argparse
import re
import textwrap

def set_academic_style():
    sns.set_theme(style="whitegrid")
    plt.rcParams.update({
        'font.family': 'serif',
        'font.size': 12,
        'axes.labelsize': 16,
        'axes.titlesize': 16,
        'xtick.labelsize': 16,
        'ytick.labelsize': 16,
        'legend.fontsize': 16,
        'figure.titlesize': 22
    })

def parse_codeql_summary(csv_path):
    df = pd.read_csv(csv_path)
    
    data = []
    for _, row in df.iterrows():
        # Parse scenario string: cwe119_scenario01
        # We need CWE ID and Scenario Number
        # The 'cwe' column has 'cwe119', 'scenario' has 'cwe119_scenario01'
        
        cwe_str = row['cwe'] # cwe119
        cwe_id = cwe_str.replace('cwe', '')
        
        scen_str = row['scenario']
        match = re.search(r'scenario(\d+)', scen_str)
        if match:
            scen_num = int(match.group(1))
            
            # Valid is Total - Error
            valid_count = row['total'] - row['error']
            
            data.append({
                'Model': row['model'],
                'CWE': cwe_id,
                'Scenario_Num': scen_num,
                'Secure_Count': row['secure'],
                'Total_Count': row['total'],
                'Valid_Count': valid_count,
                'Generated_Count': row['total']
            })
            
    return pd.DataFrame(data)

def parse_original_results(csv_path):
    df = pd.read_csv(csv_path)
    # Filter for C language
    df = df[df['Lang'] == 'c'].copy()
    
    data = []
    for _, row in df.iterrows():
        # Parse CWE-Scn: 119-0
        cwe_scn = row['CWE-Scn']
        parts = cwe_scn.split('-')
        if len(parts) == 2:
            cwe_id = parts[0]
            scen_num_orig = int(parts[1])
            # Map index: Original 0 -> 1
            scen_num = scen_num_orig + 1
            
            valid = row['#Valid']
            vuln = row['#Vulnerable']
            secure = valid - vuln
            
            data.append({
                'Model': 'Copilot',
                'CWE': cwe_id,
                'Scenario_Num': scen_num,
                'Secure_Count': secure,
                'Total_Count': valid,
                'Valid_Count': valid,
                'Generated_Count': 25 # Original paper generated 25 samples per scenario
            })
            
    return pd.DataFrame(data)

def plot_valid_rate(df, output_dir):
    # Create a unique identifier for scenario: CWE-ScenarioNum
    df['Scen_ID'] = df['CWE'] + '-' + df['Scenario_Num'].astype(str)
    
    # Find common scenarios across ALL models
    # Pivot to check presence
    presence = df.pivot_table(index='Scen_ID', columns='Model', values='Total_Count', aggfunc='count')
    
    # Keep Scen_IDs where all models have data
    common_scens = presence.dropna().index
    
    print(f"Found {len(common_scens)} common scenarios for Valid Rate plot across models: {presence.columns.tolist()}")
    
    df_filtered = df[df['Scen_ID'].isin(common_scens)].copy()

    # Filter out models with no Generated_Count (Original)
    df_valid = df_filtered.dropna(subset=['Generated_Count']).copy()
    
    if df_valid.empty:
        print("No data for Valid Rate plot.")
        return

    # Aggregate by CWE and Model
    df_agg = df_valid.groupby(['Model', 'CWE'])[['Valid_Count', 'Generated_Count']].sum().reset_index()
    
    # Calculate Rate
    df_agg['Valid_Rate'] = (df_agg['Valid_Count'] / df_agg['Generated_Count']) * 100
    
    # Sort by CWE
    try:
        df_agg['CWE_Int'] = df_agg['CWE'].astype(int)
        df_agg = df_agg.sort_values(['CWE_Int'])
    except:
        df_agg = df_agg.sort_values(['CWE'])

    # Plot
    fig, ax = plt.subplots(figsize=(16, 8))
    
    sns.barplot(x='CWE', y='Valid_Rate', hue='Model', data=df_agg, palette='muted', edgecolor='black', linewidth=0.5)
    
    # Add vertical lines
    unique_cwes = df_agg['CWE'].unique()
    for i in range(len(unique_cwes) - 1):
        ax.axvline(x=i + 0.5, color='gray', linestyle='--', linewidth=0.8, alpha=0.7)
    
    ax.set_xlabel('CWE ID')
    ax.set_ylabel('Valid Rate (%)')
    ax.set_title('Aggregated Valid Rate by CWE (Shared Scenarios Only)')
    ax.set_ylim(0, 105)
    
    plt.legend(loc='upper center', bbox_to_anchor=(0.5, -0.15), ncol=len(df_agg['Model'].unique()), frameon=False)
    
    plt.tight_layout()
    output_path = os.path.join(output_dir, 'valid_rate_aggregated.png')
    plt.savefig(output_path, dpi=300, bbox_inches='tight')
    print(f"Saved valid rate plot to {output_path}")

    # Save CSV
    csv_path = os.path.join(output_dir, 'valid_rate_aggregated.csv')
    df_agg.to_csv(csv_path, index=False)
    print(f"Saved valid rate data to {csv_path}")

    plt.close()

def plot_comparison(df, output_dir):
    # Create a unique identifier for scenario: CWE-ScenarioNum
    df['Scen_ID'] = df['CWE'] + '-' + df['Scenario_Num'].astype(str)
    
    # Find common scenarios across ALL models
    # Pivot to check presence
    # We just need to know if a Scen_ID exists for a Model
    presence = df.pivot_table(index='Scen_ID', columns='Model', values='Total_Count', aggfunc='count')
    
    # Keep Scen_IDs where all models have data
    common_scens = presence.dropna().index
    
    print(f"Found {len(common_scens)} common scenarios across models: {presence.columns.tolist()}")
    
    df_filtered = df[df['Scen_ID'].isin(common_scens)].copy()
    
    # Now Aggregate by CWE and Model
    df_agg = df_filtered.groupby(['Model', 'CWE'])[['Secure_Count', 'Total_Count']].sum().reset_index()
    
    # Calculate Rate
    df_agg['Secure_Rate'] = (df_agg['Secure_Count'] / df_agg['Total_Count']) * 100
    
    # Sort by CWE
    try:
        df_agg['CWE_Int'] = df_agg['CWE'].astype(int)
        df_agg = df_agg.sort_values(['CWE_Int'])
    except:
        df_agg = df_agg.sort_values(['CWE'])

    # Plot
    fig, ax = plt.subplots(figsize=(16, 8))
    
    # Use a slightly narrower bar width to create more space between groups if possible, 
    # but seaborn doesn't expose width easily in barplot without dodging issues.
    # Instead, we rely on the figure size and adding separators.
    
    sns.barplot(x='CWE', y='Secure_Rate', hue='Model', data=df_agg, palette='muted', edgecolor='black', linewidth=0.5)
    
    # Add vertical lines to separate CWEs clearly
    # Categorical x-axis positions are 0, 1, 2, ...
    # Separators should be at 0.5, 1.5, 2.5, ...
    unique_cwes = df_agg['CWE'].unique()
    for i in range(len(unique_cwes) - 1):
        ax.axvline(x=i + 0.5, color='gray', linestyle='--', linewidth=0.8, alpha=0.7)

    
    ax.set_xlabel('CWE ID')
    ax.set_ylabel('Secure Rate (%)')
    ax.set_title('Aggregated Secure Rate by CWE (Shared Scenarios Only)')
    ax.set_ylim(0, 105)
    
    plt.legend(loc='upper center', bbox_to_anchor=(0.5, -0.15), ncol=len(df_agg['Model'].unique()), frameon=False)
    
    plt.tight_layout()
    output_path = os.path.join(output_dir, 'comparison_secure_rate_aggregated.png')
    plt.savefig(output_path, dpi=300, bbox_inches='tight')
    print(f"Saved aggregated comparison plot to {output_path}")

    # Save CSV
    csv_path = os.path.join(output_dir, 'comparison_secure_rate_aggregated.csv')
    df_agg.to_csv(csv_path, index=False)
    print(f"Saved aggregated comparison data to {csv_path}")

    plt.close()

def plot_overall_valid_rate(df, output_dir):
    # Create a unique identifier for scenario: CWE-Scenario_Num
    df['Scen_ID'] = df['CWE'] + '-' + df['Scenario_Num'].astype(str)
    
    # Find common scenarios across ALL models
    presence = df.pivot_table(index='Scen_ID', columns='Model', values='Total_Count', aggfunc='count')
    common_scens = presence.dropna().index
    
    df_filtered = df[df['Scen_ID'].isin(common_scens)].copy()
    df_valid = df_filtered.dropna(subset=['Generated_Count']).copy()
    
    if df_valid.empty:
        print("No data for Overall Valid Rate plot.")
        return

    # Aggregate by Model ONLY
    df_agg = df_valid.groupby(['Model'])[['Valid_Count', 'Generated_Count']].sum().reset_index()
    
    # Calculate Rate
    df_agg['Valid_Rate'] = (df_agg['Valid_Count'] / df_agg['Generated_Count']) * 100
    
    # Plot
    fig, ax = plt.subplots(figsize=(7, 6))
    
    # Use hue='Model' to generate legend automatically
    sns.barplot(x='Model', y='Valid_Rate', hue='Model', data=df_agg, palette='muted', edgecolor='black', linewidth=0.5, dodge=False)
    
    ax.set_xlabel('')
    ax.set_ylabel('Overall Valid Rate (%)')
    ax.set_title('Overall Valid Rate (Shared Scenarios Only)')
    ax.set_ylim(0, 105)

    # Remove legend
    if ax.get_legend():
        ax.get_legend().remove()

    # Wrap and rotate x-axis labels
    labels = [textwrap.fill(label.get_text(), 9) for label in ax.get_xticklabels()]
    ax.set_xticklabels(labels, rotation=0)
    
    # Add value labels
    for p in ax.patches:
        height = p.get_height()
        if height > 0:
            ax.text(p.get_x() + p.get_width()/2., height + 1,
                    f'{height:.1f}%',
                    ha='center', va='bottom', fontweight='bold')
    
    plt.tight_layout()
    output_path = os.path.join(output_dir, 'overall_valid_rate.png')
    plt.savefig(output_path, dpi=300, bbox_inches='tight')
    print(f"Saved overall valid rate plot to {output_path}")

    # Save CSV
    csv_path = os.path.join(output_dir, 'overall_valid_rate.csv')
    df_agg.to_csv(csv_path, index=False)
    print(f"Saved overall valid rate data to {csv_path}")

    plt.close()

def main():
    parser = argparse.ArgumentParser(description="Compare Original vs New Results")
    parser.add_argument("codeql_csv", help="Path to codeql_analysis_summary.csv")
    parser.add_argument("original_csv", help="Path to original_result.csv")
    parser.add_argument("--output_dir", default="plots/comparison", help="Directory to save plots")
    
    args = parser.parse_args()
    
    if not os.path.exists(args.output_dir):
        os.makedirs(args.output_dir)
        
    # Set style
    set_academic_style()

    df_new = parse_codeql_summary(args.codeql_csv)
    df_orig = parse_original_results(args.original_csv)
    
    # Combine
    df_combined = pd.concat([df_new, df_orig], ignore_index=True)

    # Save combined raw data
    combined_csv_path = os.path.join(args.output_dir, 'all_combined_results.csv')
    df_combined.to_csv(combined_csv_path, index=False)
    print(f"Saved combined raw results to {combined_csv_path}")
    
    plot_comparison(df_combined, args.output_dir)
    plot_valid_rate(df_combined, args.output_dir)
    plot_overall_valid_rate(df_combined, args.output_dir)

if __name__ == "__main__":
    main()
