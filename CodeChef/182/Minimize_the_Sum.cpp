/**
*    created: 2025-04-16 20:32:51
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
        int n;
        cin >> n;
        vector<vector<int>> g(n, vector<int>(n));
        int mxv = 0;
    
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                cin >> g[i][j];
                mxv = max(mxv, g[i][j]);
            }
        }
        vector<vector<int>> rows(n, vector<int>(n)), pref(n, vector<int>(n + 1, 0));
        rows = g;
        set<int> st;
        st.insert(1);
        for (int i = 0; i < n; ++i) {
            sort(rows[i].begin(), rows[i].end());
            for (int j = 0; j < n; ++j) {
                pref[i][j+1] = pref[i][j] + rows[i][j];
                st.insert(rows[i][j]);
                st.insert(rows[i][j] + 1);
            }
        }
        st.insert(mxv);

        vector<int> pos(n, 0);
     
        int ans = 0, res = -1;
    
        for (int x : st) {
            for (int i = 0; i < n; ++i) {
                while (pos[i] < n && rows[i][pos[i]] <= x) {
                    pos[i]++;
                }
            }
     
            int f1 = pref[0][pos[0]] + x * (n - pos[0]);
            int sc = 0;
            for (int i = 1; i < n; ++i) {
                int fi = pref[i][pos[i]] + x * (n - pos[i]);
                if (fi > f1) {
                    sc++;
                }
            }
     
            if (sc > res) {
                res = sc;
                ans = x;
            }
        }
     
        cout << ans << "\n";
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}