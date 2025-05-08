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
        string t;
        cin >> n >> t;
        // 1‑index it and set s[0] = '0'
        string s = "0" + t;

        // 1) Count total transitions T = |{ i : 1<=i<=n, s[i] != s[i-1] }|
        int T = 0;
        for(int i = 1; i <= n; i++)
            if(s[i] != s[i - 1])
                T++;

        // 2) Collect the two “directions” of transitions
        //    Left‑boundary transitions at i (for i=1..n):
        //      0→1 at i goes into L01,  1→0 into L10
        vector<int> L01, L10;
        for(int i = 1; i <= n; i++) {
            if(s[i] == s[i - 1]) continue;
            if(s[i - 1] == '0')        L01 .push_back(i);
            else /* s[i-1]=='1' */   L10 .push_back(i);
        }

        //    Right‑boundary transitions at j (for j=1..n‑1):
        //      0→1 at j goes into R01,  1→0 into R10
        vector<int> R01, R10;
        for(int j = 1; j < n; j++) {
            if(s[j] == s[j + 1]) continue;
            if(s[j] == '0')          R01 .push_back(j);
            else /* s[j]=='1' */     R10 .push_back(j);
        }

        // 3) Can we get a total gain G = 2?
        //    That happens iff we can pick a left‑transition at i and
        //    a strictly later right‑transition at j of the *same* type.
        bool can2 = false;
        if(!L01.empty() && !R01.empty() && L01.front() < R01.back())
            can2 = true;
        if(!L10.empty() && !R10.empty() && L10.front() < R10.back())
            can2 = true;

        // 4) Otherwise, can we get gain G = 1?
        //    Two simple “one‑boundary” fixes suffice:
        //    a) reverse a suffix [i..n] to fix the left boundary at i (no right effect)
        //       ⇔ we need s[i] != s[i-1]  AND  s[n] == s[i-1]
        //    b) reverse a prefix [1..j] to fix the right boundary at j
        //       ⇔ we need s[j] != s[j+1] AND  s[1] == s[j+1]
        bool can1 = false;
        for(int i : L01)
            if(s[n] == s[i - 1])
                can1 = true;
        for(int i : L10)
            if(s[n] == s[i - 1])
                can1 = true;
        for(int j : R01)
            if(s[1] == s[j + 1])
                can1 = true;
        for(int j : R10)
            if(s[1] == s[j + 1])
                can1 = true;

        int G = can2 ? 2 : (can1 ? 1 : 0);

        // 5) Answer = (presses = n) + (moves = T)  − (max possible gain)
        cout << (n + T - G) << "\n";
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}