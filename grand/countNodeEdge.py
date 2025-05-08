from collections import defaultdict

# Create a graph using adjacency list
class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
    
    # Function to add edge to the graph
    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)  # Undirected graph

    # DFS to count nodes and edges
    def dfs(self, node, visited):
        visited.add(node)
        nodes = 1  # Current node
        edges = len(self.graph[node])  # All connected edges

        for neighbor in self.graph[node]:
            if neighbor not in visited:
                sub_nodes, sub_edges = self.dfs(neighbor, visited)
                nodes += sub_nodes
                edges += sub_edges
        
        return nodes, edges

# Create the graph
g = Graph()
g.add_edge(1, 2)
g.add_edge(2, 3)
g.add_edge(3, 4)
g.add_edge(3, 1)
g.add_edge(4, 1)
g.add_edge(5,6)
g.add_edge(6,7)

# To store visited nodes
visited = set()

# Assume we are starting from node 1
num_nodes, num_edges = g.dfs(1, visited)

# Divide edges by 2 for undirected graph
print("Number of Nodes:", num_nodes)
print("Number of Edges:", num_edges // 2)

# how to run python file in terminal?
