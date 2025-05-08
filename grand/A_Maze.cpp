/**
*    created: 2025-03-27 06:19:11
**/
#include<bits/stdc++.h>
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
/*
Pavel loves grid mazes. A grid maze is an n × m rectangle maze where each cell is either empty, 
or is a wall. You can go from one cell to another only if both cells are empty and have a common side.

Pavel drew a grid maze with all empty cells forming a connected area. That is, you can go from any empty 
cell to any other one. Pavel doesn't like it when his maze has too little walls. He wants to turn exactly k 
empty cells into walls so that all the remaining cells still formed a connected area. Help him.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n,m,k;
        cin >> n >> m >> k;
        int total  = 0;
        vector<string> grid(n);
        for(int i = 0; i < n; ++i){
            cin >> grid[i];
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '.') total++;
            }
        }
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = total - k, curr = 0;
        function<void(int,int)> dfs = [&](int i, int j){
            if(curr == cnt) return;
            if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == '#') return;
            curr++;
            vis[i][j] = 1;
            dfs(i+1, j);
            dfs(i-1, j);
            dfs(i, j+1);
            dfs(i, j-1);
        };
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '.'){
                    dfs(i, j);
                }
            }
        }
        debug(vis);
        int walls = k;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '.' && !vis[i][j]){
                    grid[i][j] = 'X';
                    walls--;
                }
            }
        }
        for(int i = 0; i < n; ++i){
            cout << grid[i] << endl;
        }
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}
