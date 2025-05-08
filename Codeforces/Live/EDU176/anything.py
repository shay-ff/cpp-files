import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from scipy.cluster.hierarchy import linkage, fcluster, dendrogram
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler

# 1. Load dataset from file
def load_data(file_path):
    df = pd.read_csv(file_path)
    return df

# 2. Preprocess data: select numerical columns and normalize them
def preprocess_data(df):
    numeric_df = df.select_dtypes(include=[np.number])
    scaler = StandardScaler()
    scaled_array = scaler.fit_transform(numeric_df)
    df_scaled = pd.DataFrame(scaled_array, columns=numeric_df.columns)
    return df_scaled

# 3a. Perform K-Means clustering
def perform_kmeans_clustering(df, n_clusters=3):
    kmeans = KMeans(n_clusters=n_clusters, random_state=42)
    cluster_labels = kmeans.fit_predict(df)
    df_kmeans = df.copy()
    df_kmeans['Cluster'] = cluster_labels
    return df_kmeans, cluster_labels

# 3b. Perform Hierarchical clustering (using Ward's method)
def perform_hierarchical_clustering(df, n_clusters=3):
    linked = linkage(df, method='ward')
    cluster_labels = fcluster(linked, t=n_clusters, criterion='maxclust')
    df_hier = df.copy()
    df_hier['Cluster'] = cluster_labels
    return df_hier, cluster_labels

# 4. Create contingency table between clusters and a categorical column
def create_contingency_table(df, cluster_col, category_col):
    contingency = pd.crosstab(df[cluster_col], df[category_col])
    return contingency

# 5. Visualize a DataFrame (matrix) using a heatmap
def visualize_heatmap(data, title, annot=True, fmt=".2f", xlabel="", ylabel=""):
    plt.figure(figsize=(10, 8))
    sns.heatmap(data, annot=annot, fmt=fmt, cmap="viridis")
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.show()

# 6. Main function: execute the steps of the experiment
def main():
    # Update with your dataset path
    file_path = "data.csv"
    df = load_data("/content/cluster_data.csv")
    
    # Preprocess numerical data (normalization is important for clustering)
    df_numeric = preprocess_data(df)
    
    # Apply K-Means clustering
    df_kmeans, kmeans_labels = perform_kmeans_clustering(df_numeric.copy(), n_clusters=3)
    print("K-Means clustering results (first 5 rows):")
    print(df_kmeans.head())
    
    # Apply Hierarchical clustering
    df_hier, hierarchical_labels = perform_hierarchical_clustering(df_numeric.copy(), n_clusters=3)
    print("\nHierarchical clustering results (first 5 rows):")
    print(df_hier.head())
    
    # Visualize clusters using a heatmap of the correlation matrix (from K-Means result)
    visualize_heatmap(df_kmeans.corr(), title="K-Means Cluster Data Correlation Heatmap")
    
    # Generate and visualize contingency table if a categorical column exists
    # For example, assume your dataset has a column named 'Category'
    if 'Category' in df.columns:
        # Merge original categorical data with cluster labels (from K-Means)
        df_contingency = df.copy()
        df_contingency['Cluster'] = df_kmeans['Cluster']
        contingency_table = create_contingency_table(df_contingency, 'Cluster', 'Category')
        print("\nContingency Table:")
        print(contingency_table)
        
        visualize_heatmap(contingency_table, 
                          title="Contingency Table Heatmap", 
                          annot=True, fmt="d", 
                          xlabel="Category", ylabel="Cluster")
    else:
        print("\nNo 'Category' column found in the dataset for creating a contingency table.")

if __name__ == "__main__":
    main()
