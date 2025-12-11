import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import os
import argparse
import numpy as np

def set_academic_style():
    sns.set_theme(style="whitegrid")
    plt.rcParams.update({
        'font.family': 'serif',
        'font.size': 12,
        'axes.labelsize': 14,
        'axes.titlesize': 16,
        'xtick.labelsize': 12,
        'ytick.labelsize': 12,
        'legend.fontsize': 12,
        'figure.titlesize': 18
    })

def plot_stacked_outcomes(df, output_dir):
    """
    Generates a stacked bar chart showing the proportion of Secure, Vulnerable, and Error files for each model.
    """
    # Aggregate data by model
    model_stats = df.groupby('model')[['secure', 'vulnerable', 'error', 'total']].sum().reset_index()
    
    # Calculate percentages
    model_stats['Secure %'] = model_stats['secure'] / model_stats['total'] * 100
    model_stats['Vulnerable %'] = model_stats['vulnerable'] / model_stats['total'] * 100
    model_stats['Error %'] = model_stats['error'] / model_stats['total'] * 100
    
    # Plotting
    fig, ax = plt.subplots(figsize=(10, 6))
    
    models = model_stats['model']
    bar_width = 0.6
    
    # Academic colors (Colorblind friendly / Muted)
    # Blue for Secure, Orange/Red for Vulnerable, Gray for Error
    color_secure = '#4e79a7'  # Muted Blue
    color_vuln = '#e15759'    # Muted Red
    color_error = '#bab0ac'   # Gray
    
    p1 = ax.bar(models, model_stats['Secure %'], width=bar_width, label='Secure', color=color_secure, edgecolor='black', linewidth=0.5)
    p2 = ax.bar(models, model_stats['Vulnerable %'], width=bar_width, bottom=model_stats['Secure %'], label='Vulnerable', color=color_vuln, edgecolor='black', linewidth=0.5)
    p3 = ax.bar(models, model_stats['Error %'], width=bar_width, bottom=model_stats['Secure %'] + model_stats['Vulnerable %'], label='Compilation Error', color=color_error, edgecolor='black', linewidth=0.5)
    
    ax.set_ylabel('Percentage')
    ax.set_title('Overall Code Generation Performance by Model')
    ax.legend(loc='upper center', bbox_to_anchor=(0.5, -0.15), ncol=3, frameon=False)
    
    # Add percentage labels
    for i, row in model_stats.iterrows():
        # Secure Label
        if row['Secure %'] > 5:
            ax.text(i, row['Secure %'] / 2, f"{row['Secure %']:.1f}%", ha='center', va='center', color='white', fontweight='bold')
        
        # Vulnerable Label
        if row['Vulnerable %'] > 5:
            ax.text(i, row['Secure %'] + row['Vulnerable %'] / 2, f"{row['Vulnerable %']:.1f}%", ha='center', va='center', color='white', fontweight='bold')
            
        # Error Label
        # if row['Error %'] > 5:
        ax.text(i, row['Secure %'] + row['Vulnerable %'] + row['Error %'] / 2, f"{row['Error %']:.1f}%", ha='center', va='center', color='black', fontweight='bold')

    plt.tight_layout()
    output_path = os.path.join(output_dir, 'overall_performance_stacked.png')
    plt.savefig(output_path, dpi=300, bbox_inches='tight')
    print(f"Saved stacked bar chart to {output_path}")
    plt.close()

def plot_cwe_heatmap(df, output_dir):
    """
    Generates a heatmap of Secure Rate by CWE Scenario and Model.
    """
    # Create a readable label for the scenario
    # Assumes scenario format like 'cwe119_scenario01'
    def format_label(row):
        try:
            if 'scenario' in row['scenario']:
                parts = row['scenario'].split('_')
                cwe_part = parts[0]
                scen_part = parts[1]
                scen_num = int(scen_part.replace('scenario', ''))
                return f"{cwe_part}-{scen_num}"
            return row['scenario']
        except:
            return row['scenario']

    df['scenario_label'] = df.apply(format_label, axis=1)
    
    # Calculate secure rate per Scenario per Model
    # Use secure_rate_all if available, else calculate
    if 'secure_rate_all' not in df.columns:
         df['secure_rate_all'] = df['secure'] / df['total'] * 100
    
    # Pivot for heatmap
    heatmap_data = df.pivot(index='scenario_label', columns='model', values='secure_rate_all')
    
    # Sort index to keep CWEs together
    heatmap_data = heatmap_data.sort_index()

    # Adjust figure size based on number of rows
    height = max(8, len(heatmap_data) * 0.4)
    fig, ax = plt.subplots(figsize=(12, height))
    
    # Diverging color palette (Red to Blue)
    cmap = sns.diverging_palette(10, 240, as_cmap=True)
    
    sns.heatmap(heatmap_data, annot=True, fmt=".1f", cmap=cmap, vmin=0, vmax=100, 
                linewidths=.5, ax=ax, cbar_kws={'label': 'Secure Rate (%)'})
    
    ax.set_title('Secure Rate by CWE Scenario')
    ax.set_ylabel('Scenario')
    ax.set_xlabel('Model')
    
    plt.tight_layout()
    output_path = os.path.join(output_dir, 'cwe_performance_heatmap.png')
    plt.savefig(output_path, dpi=300, bbox_inches='tight')
    print(f"Saved heatmap to {output_path}")
    plt.close()

def plot_secure_rate_distribution(df, output_dir):
    """
    Generates a box plot showing the distribution of secure rates across scenarios for each model.
    This helps visualize consistency.
    """
    # Calculate secure rate for each scenario row
    # The CSV already has 'secure_rate_all' (which includes errors as non-secure)
    # Let's recalculate to be sure or use the existing one.
    # The user's CSV has 'secure_rate_all'.
    
    # If 'secure_rate_all' is not in columns, calculate it
    if 'secure_rate_all' not in df.columns:
         df['secure_rate_all'] = df['secure'] / df['total'] * 100

    fig, ax = plt.subplots(figsize=(10, 6))
    
    # Box plot
    sns.boxplot(x='model', y='secure_rate_all', data=df, palette="Set2", ax=ax)
    sns.stripplot(x='model', y='secure_rate_all', data=df, color=".25", alpha=0.5, jitter=True, ax=ax)
    
    ax.set_title('Distribution of Secure Rates Across Scenarios')
    ax.set_ylabel('Secure Rate (%)')
    ax.set_xlabel('Model')
    
    plt.tight_layout()
    output_path = os.path.join(output_dir, 'secure_rate_distribution.png')
    plt.savefig(output_path, dpi=300, bbox_inches='tight')
    print(f"Saved distribution plot to {output_path}")
    plt.close()

def main():
    parser = argparse.ArgumentParser(description="Visualize CodeQL Analysis Results")
    parser.add_argument("csv_file", help="Path to the summary CSV file")
    parser.add_argument("--output_dir", default="plots", help="Directory to save plots")
    
    args = parser.parse_args()
    
    if not os.path.exists(args.csv_file):
        print(f"Error: File '{args.csv_file}' not found.")
        return

    if not os.path.exists(args.output_dir):
        os.makedirs(args.output_dir)
        
    # Load data
    df = pd.read_csv(args.csv_file)
    
    # Set style
    set_academic_style()
    
    # Generate plots
    plot_stacked_outcomes(df, args.output_dir)
    plot_cwe_heatmap(df, args.output_dir)
    plot_secure_rate_distribution(df, args.output_dir)

if __name__ == "__main__":
    main()
