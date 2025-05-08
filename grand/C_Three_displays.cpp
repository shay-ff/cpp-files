/**
*    created: 2025-03-14 01:36:50
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

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; ++i){
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(k == 0 || k == n){
            cout << 1 << endl;
            for(int i = 0; i < n; ++i)
                cout << (k == n) << " ";
            cout << endl;
            return;
        }
        vector<int> sub(n);
        function<void(int, int)> dfs = [&](int u, int p){
            sub[u] = 1;
            for(auto v : adj[u]){
                if(v == p) continue;
                dfs(v, u);
                sub[u] += sub[v];
            }
        };
        dfs(0, -1);
        for(int i = 0; i < n; ++i){
            if(sub[i] == k){
                vector<int> vis(n, 0);
                function<void(int, int)> dfs = [&](int u, int p){
                    vis[u] = 1;
                    for(auto v : adj[u]){
                        if(v == p) continue;
                        dfs(v, u);
                    }
                };
                dfs(i, -1);
                cout << 2 << endl;
                for(int j = 0; j < n; ++j)
                    cout << vis[j] << " ";
                cout << endl;
            }
            else if(sub[i] == n - k){
                vector<int> vis(n, 1);
                function<void(int, int)> dfs = [&](int u, int p){
                    vis[u] = 0;
                    for(auto v : adj[u]){
                        if(v == p) continue;
                        dfs(v, u);
                    }
                };
                dfs(i, -1);
                cout << 2 << endl;
                for(int j = 0; j < n; ++j)
                    cout << vis[j] << " ";
                cout << endl;
            }
        }
        // now i need to make a component of size k ones
        // and n - k zeros
        // i can do this by making a component of size k ones
        vector<int> vis(n, 0);
        int cntr = k;
        function<void(int, int)> dfs = [&](int u, int p){
            if(cntr == 0) return;
            vis[u] = 1;
            cntr--;
            for(auto v : adj[u]){
                if(v == p) continue;
                dfs(v, u);
            }
        };
        dfs(0, -1);
        cout << 3 << endl;
        for(int i = 0; i < n; ++i)
            cout << vis[i] << " ";
        cout << endl;

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}