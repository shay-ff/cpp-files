/**
*    created: 2025-04-24 20:08:36
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
        if(n == x){
            for(int i = 0; i < n; ++i) {
                cout << i << " ";
            }
            cout << endl;
            return;
        }
        for(int i = 0; i < x; ++i) {
            cout << i << " ";
        }
        for(int i = x + 1; i < n; ++i) {
            cout << i << " ";
        }
        cout << x << endl;
    };

    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}