#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> graph;

// Function to find the shortest palindrome path
int find_shortest_path(int src, int dst) {
    if (src == dst) return 0;  // Empty path is a palindrome
    
    queue<tuple<int, string, int>> q;  // (current node, current path, depth)
    unordered_set<string> visited;  // Store (node, path_hash) as a string
    
    q.emplace(src, "", 0);
    
    while (!q.empty()) {
        auto [node, path, depth] = q.front();
        q.pop();
        
        // Check if path is a palindrome and reaches the destination
        if (node == dst && equal(path.begin(), path.begin() + path.size()/2, path.rbegin())) {
            return depth;
        }
        
        // Explore all outgoing edges
        for (int next_node = 0; next_node < N; ++next_node) {
            if (graph[node][next_node] == '-') continue;
            
            string new_path = path + graph[node][next_node];
            string state = to_string(next_node) + "_" + new_path;  // Unique state representation
            
            if (visited.find(state) == visited.end()) {
                visited.insert(state);
                q.emplace(next_node, new_path, depth + 1);
            }
        }
    }
    
    return -1;  // No valid palindrome path found
}

int main() {
    cin >> N;
    graph.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> graph[i];
    }

    vector<vector<int>> results(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            results[i][j] = find_shortest_path(i, j);
        }
    }

    // Print results
    for (const auto &row : results) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

