#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPointInRange(long long p, long long start, long long end) {
        return min(start, end) <= p && p <= max(start, end);
    }

public:
    pair<pair<long long, long long>, int> solveSantaPath(
        int N,
        vector<pair<long long, long long>>& houses,
        long long Sx, long long Sy,
        int M,
        vector<pair<char, long long>>& moves
    ) {
        // Maps for efficient lookup
        map<long long, set<long long>> houses_by_x;  // x -> set of y coordinates
        map<long long, set<long long>> houses_by_y;  // y -> set of x coordinates
        
        // Build lookup maps
        for (const auto& house : houses) {
            long long x = house.first;
            long long y = house.second;
            houses_by_x[x].insert(y);
            houses_by_y[y].insert(x);
        }
        
        // Set to track visited houses
        set<pair<long long, long long>> visited;
        
        // Current position
        long long x = Sx, y = Sy;
        
        // Process each move
        for (const auto& move : moves) {
            char direction = move.first;
            long long distance = move.second;
            
            long long new_x = x, new_y = y;
            
            // Calculate new position and check for houses on the path
            if (direction == 'U' || direction == 'D') {
                // Vertical movement
                new_y = (direction == 'U') ? y + distance : y - distance;
                
                // Check houses that share the same x-coordinate
                auto it = houses_by_x.find(x);
                if (it != houses_by_x.end()) {
                    for (long long house_y : it->second) {
                        if (isPointInRange(house_y, y, new_y)) {
                            visited.insert({x, house_y});
                        }
                    }
                }
            } else {
                // Horizontal movement (L/R)
                new_x = (direction == 'R') ? x + distance : x - distance;
                
                // Check houses that share the same y-coordinate
                auto it = houses_by_y.find(y);
                if (it != houses_by_y.end()) {
                    for (long long house_x : it->second) {
                        if (isPointInRange(house_x, x, new_x)) {
                            visited.insert({house_x, y});
                        }
                    }
                }
            }
            
            x = new_x;
            y = new_y;
        }
        
        return {{x, y}, visited.size()};
    }
};

// Example usage
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    long long Sx, Sy;
    cin >> Sx >> Sy;
    
    // Input format:
    // N
    // X1 Y1
    // X2 Y2
    // ...
    // XN YN
    // Sx Sy
    // M
    // D1 C1
    // D2 C2
    // ...
    // DM CM
    
    cin >> N;
    vector<pair<long long, long long>> houses(N);
    for (int i = 0; i < N; i++) {
        cin >> houses[i].first >> houses[i].second;
    }
    
    
    cin >> M;
    vector<pair<char, long long>> moves(M);
    for (int i = 0; i < M; i++) {
        cin >> moves[i].first >> moves[i].second;
    }
    
    Solution solution;
    auto result = solution.solveSantaPath(N, houses, Sx, Sy, M, moves);
    
    cout << result.first.first << " " << result.first.second << "\n";  // Final position
    cout << result.second << "\n";  // Number of houses visited
    
    return 0;
}