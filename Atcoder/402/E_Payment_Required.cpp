/**
*    created: 2025-04-19 17:53:01
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto solve_test = [&](int test_case) {
        int n, x;
        cin >> n >> x;
        using ld = long double;
        vector<ld> score(n), prob(n);
        vector<int> cost(n);
        for(int i = 0; i < n; i++) {
            int pi;
            cin >> score[i] >> cost[i] >> pi;
            prob[i] = pi / 100.0L;
        }

        int m = 1 << n;
        vector<vector<ld>> dp(m, vector<ld>(x + 1, 0.0));

        for(int cnt = m - 1; cnt >= 0; --cnt) {
            for(int c = x; c >= 0; --c) {
                ld maxsc = 0.0;
                for(int i = 0; i < n; i++) {
                    if(cnt & (1 << i)) 
                        continue;
                    int tot = c + cost[i];
                    if(tot > x) 
                        continue;
                    int new_sub = cnt | (1 << i);
                    ld success_p = score[i] + dp[new_sub][tot];
                    ld curr_prob = prob[i] * success_p + (1.0L - prob[i]) * dp[cnt][tot];
                    maxsc = max(maxsc, curr_prob);
                }
                dp[cnt][c] = maxsc;
            }
        }
        cout << fixed << setprecision(17) << dp[0][0] << "\n";
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}