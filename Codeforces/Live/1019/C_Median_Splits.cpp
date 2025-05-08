/**
*    created: 2025-04-21 20:33:04
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
const int INF = 2e18;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto solve_test = [&](int test_case) {
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<int> prefix_k(n + 1);
        prefix_k[0] = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] <= k) prefix_k[i] = 1;
            else prefix_k[i] = -1;
            prefix_k[i] += prefix_k[i - 1];
        }
        int fsum = prefix_k[n];

        vector<int> sum_sofar(n + 1, INF), pos_pref(n + 1, INF);
        int minp = INF, posp = INF;
        for(int i = 1; i < n; i++) {
            minp = min(minp, prefix_k[i]);
            if(prefix_k[i] >= 0)
                posp = min(posp, prefix_k[i]);
            sum_sofar[i] = minp;
            pos_pref[i] = posp;
        }

        vector<bool> can_split(n + 1, false);
        bool f = false;
        for(int i = n - 1; i >= 1; i--) {
            if(prefix_k[i] <= fsum)
                f = true;
            can_split[i] = f;
        }
        bool can = false;
        for(int i = 2; i < n && !can; i++) {
            if(pos_pref[i - 1] != INF && prefix_k[i] >= pos_pref[i - 1]) {
                can = true;
                break;
            }
            if(sum_sofar[i - 1] <= prefix_k[i] && prefix_k[i] <= fsum) {
                can = true;
                break;
            }
        }

        if(!can) {
            int have = -1;
            for(int i = 1; i <= n - 2; i++) {
                if(prefix_k[i] >= 0) {
                    have = i;
                    break;
                }
            }
            if(have != -1 && can_split[have + 1]) {
                can = true;
            }
        }

        if(can) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}