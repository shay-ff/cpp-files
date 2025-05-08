/**
*    created: 2025-04-03 20:27:20
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
        vector<int> a(n + 1), q(n + 1);
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        for(int i = 1; i <= n; ++i){
            cin >> q[i];
        }
        vector<int> rem(n + 1, 0), pos, vis(n + 1, 0);
        int cyc = 0, op = 0;
        for(int i = 1; i <= n; ++i){
            if (!vis[i]){
                cyc++;
                int id = i, cntr = 0;
                while (!vis[id]){
                    vis[id] = true;
                    rem[id] = cyc;
                    cntr++;
                    id = a[id];
                }
                pos.push_back(cntr);
            }
        }
        vector<int> cnt(cyc + 1, 0), ans;
        for(int i = 1; i <= n; ++i){
            int p = rem[q[i]];
            if(!cnt[p]){
                cnt[p] = 1;
                op += pos[p - 1];
            }
            ans.push_back(op);
        }
        for(int i = 0; i < n; ++i)
            cout << ans[i] << " \n"[i == n - 1];
        

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}