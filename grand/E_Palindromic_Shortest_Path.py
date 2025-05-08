from collections import deque

def solve():
    N = int(input())
    graph = [input().strip() for _ in range(N)]
    
    # BFS function to find shortest palindrome path
    def find_shortest_path(src, dst):
        if src == dst:
            return 0  # Empty path is already a palindrome
        
        queue = deque([(src, "", 0)])  # (current node, current path, depth)
        visited = set()  # Store (node, path_hash) to avoid redundant searches
        
        while queue:
            node, path, depth = queue.popleft()
            
            # Check if current path is a palindrome and ends at destination
            if node == dst and path == path[::-1]:
                return depth
            
            # Explore neighbors
            for next_node in range(N):
                if graph[node][next_node] == '-':
                    continue
                
                new_path = path + graph[node][next_node]
                state = (next_node, hash(new_path))
                
                if state not in visited:
                    visited.add(state)
                    queue.append((next_node, new_path, depth + 1))
        
        return -1  # No valid palindrome path found

    # Compute results for all vertex pairs
    results = []
    for i in range(N):
        row = [find_shortest_path(i, j) for j in range(N)]
        results.append(row)
    
    # Print results
    for row in results:
        print(" ".join(map(str, row)))
