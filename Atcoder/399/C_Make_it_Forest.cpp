/**
*    created: 2025-03-29 17:34:27
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
You are given a simple undirected graph with 
N vertices and 
M edges, where the vertices are labeled 
1 to 
N. The 
i-th edge connects vertices 
u 
i
​
  and 
v 
i
​
 .
What is the minimum number of edges that need to be deleted from this graph so that the graph becomes a forest?
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        for(int i = 0; i < m; ++i){
            int u,v;
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int temp = 0;
        function<int(int)> dfs = [&](int u){
            vis[u] = 1;
            int cnt = 1;
            for(int v : g[u]){
                if(!vis[v]){
                    cnt += dfs(v);
                }
            }
            return cnt;
        };
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                temp++;
                int cnt = dfs(i);
                ans += cnt - 1;
            }
        }
        ans = m - (n - temp);
        cout << ans << endl;
    };
    int T = 1;
    // cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}