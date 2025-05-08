/**
*    created: 2025-04-19 17:37:08
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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> ar(m);
        for (int i = 0; i < m; i++) {
            int K;
            cin >> K;
            ar[i].resize(K);
            for (int j = 0; j < K; j++) {
                cin >> ar[i][j];
            }

        }

        vector<int> days(n + 1);
        for (int i = 1; i <= n; i++) {
            int d;
            cin >> d;
            days[d] = i;
        }


        vector<int> cnt(n + 1, 0);
        for (const auto& x : ar) {
            if (x.empty()) {
                cnt[0]++;
            } 
            else {
                int t = 0;
                for (int ing : x) {
                    t = max(t, days[ing]);
                }
                cnt[t]++;
            }
        }


        vector<int> ans(n + 1, 0);
        int accu = cnt[0];
        for (int i = 1; i <= n; i++) {
            accu += cnt[i];
            ans[i] = accu;
        }

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << '\n';
        }
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}