/**
*    created: 2025-04-07 10:47:49
**/
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    auto solve_test = [&](int test_case){
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        
        // Compute distance from obstacles using multisource BFS
        vector<vector<int>> obstacles(n, vector<int>(m, -1));
        queue<pair<int,int>> q;
        pair<int,int> start, end;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'S'){
                    start = {i, j};
                } 
                else if (grid[i][j] == 'E'){
                    end = {i, j};
                }
                else if (grid[i][j] == '*'){
                    obstacles[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        // Multi-source BFS from all obstacles
        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for (int dx = -1; dx <= 1; ++dx){
                for (int dy = -1; dy <= 1; ++dy){
                    if (abs(dx) == abs(dy)) continue;
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (obstacles[nx][ny] != -1) continue;
                    obstacles[nx][ny] = obstacles[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        // 'can(mid)' returns true if there exists a path from S to E
        // where each cell on the path has obstacles distance >= mid
        auto can = [&](int mid) -> bool {
            if (obstacles[start.first][start.second] < mid) return false;
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            queue<array<int,3>> qq; 
            qq.push({start.first, start.second, obstacles[start.first][start.second]});
            vis[start.first][start.second] = true;
            
            while (!qq.empty()){
                auto [x, y, curr] = qq.front();
                qq.pop();
                if (x == end.first && y == end.second){
                    return true;
                }
                for (int dx = -1; dx <= 1; ++dx){
                    for (int dy = -1; dy <= 1; ++dy){
                        if (abs(dx) == abs(dy)) continue;
                        int nx = x + dx, ny = y + dy;
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny]) continue;
                        if (obstacles[nx][ny] < mid) continue;
                        vis[nx][ny] = true;
                        qq.push({nx, ny, min(curr, obstacles[nx][ny])});
                    }
                }
            }
            return false;
        };
        
        int low = 0, high = n + m, ans = -1;
        while (low <= high){
            int mid = (low + high) / 2;
            if (can(mid)){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        show(ans);
    };
    
    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; ++i){
        solve_test(i);
    }
    
    return 0;
}
