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
    auto solve_test = [&](int test_case) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        if (k == 0 || k == n) {
            cout << 1 << "\n";
            for (int i = 0; i < n; i++)
                cout << (k == n) << " ";
            cout << "\n";
            return;
        }
        
        vector<int> sub(n, 0), par(n, -1);
        function<void(int, int)> dfs_subtree = [&](int u, int p) {
            par[u] = p;
            sub[u] = 1;
            for (int v : adj[u]) {
                if (v == p) continue;
                dfs_subtree(v, u);
                sub[u] += sub[v];
            }
        };
        dfs_subtree(0, -1);
        
        for (int i = 0; i < n; i++) {
            if (sub[i] == k) {
                vector<int> label(n, 0);
                function<void(int, int)> mark_subtree = [&](int u, int p) {
                    label[u] = 1;
                    for (int w : adj[u]) {
                        if (w == p) continue;
                        if (par[w] == u) {
                            mark_subtree(w, u);
                        }
                    }
                };
                mark_subtree(i, par[i]);
                cout << 2 << "\n";
                for (int j = 0; j < n; j++)
                    cout << label[j] << " ";
                cout << "\n";
                return;
            }
            else if (sub[i] == n - k) {
                vector<int> label(n, 1);
                function<void(int, int)> mark_subtree = [&](int u, int p) {
                    label[u] = 0;
                    for (int w : adj[u]) {
                        if (w == p) continue;
                        if (par[w] == u) {
                            mark_subtree(w, u);
                        }
                    }
                };
                mark_subtree(i, par[i]);
                cout << 2 << "\n";
                for (int j = 0; j < n; j++)
                    cout << label[j] << " ";
                cout << "\n";
                return;
            }
        }
        
        vector<int> label(n, 0);
        int cnt = k;
        function<void(int, int)> dfs_pick = [&](int u, int p) {
            if (cnt == 0) return;
            label[u] = 1;
            cnt--;
            for (int v : adj[u]) {
                if (v == p) continue;
                if (cnt == 0) break;
                dfs_pick(v, u);
            }
        };
        dfs_pick(0, -1);
        cout << 3 << "\n";
        for (int i = 0; i < n; i++)
            cout << label[i] << " ";
        cout << "\n";
    };

    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}
