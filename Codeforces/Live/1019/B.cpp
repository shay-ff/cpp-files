/**
*    created: 2025-04-21 20:09:10
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
        s = "0" + s;
        set<char> st;
        for(int i = 1; i <= n; ++i) {
            st.insert(s[i]);
        }
        if(st.size() == 1) {
            if(s[1] == '0') {
                cout << n << "\n";
                return;
            }
            cout << n + 1 << "\n";
            return;
        }
        int diff = 0;
        int left_subtr01 = n + 1, left_subtr10 = n + 1, right_subtr01 = 0,   right_subtr10 = 0;

        for(int i = 1; i <= n; ++i) {
            if(s[i] != s[i - 1]) {
                ++diff;
                if(s[i] == '1')  left_subtr01 = min(left_subtr01, i);
                else               left_subtr10 = min(left_subtr10, i);
            }
            if(i < n && s[i] != s[i + 1]) {
                if(s[i] == '0')  right_subtr01 = max(right_subtr01, i);
                else               right_subtr10 = max(right_subtr10, i);
            }
        }

        bool res = false, res2 = false;

        if ((left_subtr01 < right_subtr01) || (left_subtr10 < right_subtr10)) {
            res2 = true;
        }

        if ((left_subtr01 <= n && s[n] == '0')|| (left_subtr10 <= n && s[n] == '1')|| (right_subtr01 >= 1 && s[1] == '1')|| (right_subtr10 >= 1 && s[1] == '0')) {
            res = true;
        }

        int pass = 0;
        if (res2) {
            pass = 2;
        } else if (res) {
            pass = 1;
        }
        show(n + diff - pass);

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}