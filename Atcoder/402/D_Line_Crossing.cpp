/**
*    created: 2025-04-19 17:46:29
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
        int n, m;
        cin >> n >> m;

        vector<int> mod;

        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            int s = (a + b) % n;
            mod.push_back(s);
        }

        sort(mod.begin(), mod.end());

        int pll = 0;
        for(int i = 0, j = 0; i < m; i = j) {
            j = i + 1;
            while(j < m && mod[j] == mod[i]) j++;
            int c = j - i;
            pll += c * (c - 1) / 2;
        }
        int ans = m * (m - 1) / 2 - pll;
        show(ans);
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}
