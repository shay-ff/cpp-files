/**
*    created: 2025-04-19 20:05:50
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
        int n;
        string s;
        cin >> n >> s;

        int minv = count(s.begin(), s.end(), '<');
        vector<int> ans(n);
        ans[0] = minv + 1;
        int l = minv, r = minv + 2;

        for(int i = 1; i < n; ++i) {
            if(s[i - 1] == '<') {
                ans[i] = l--;
            } else {
                ans[i] = r++;
            }
        }

        for(int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    };

    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}