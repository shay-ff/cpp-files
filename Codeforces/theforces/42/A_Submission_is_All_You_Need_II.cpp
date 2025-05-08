/**
*    created: 2025-04-08 14:09:00
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
        cout << n << endl;
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}
// 1 : 1
// 2 : 2, 3 (3 - (3 mod 2) = 2)
// 3 : 3, 4, 5 (5 - (5 mod 3) = 3)
// 4 : 4, 5, 6, 7 (7 - (7 mod 4) = 4)
// n : n, n+1, n+2, ..., 2n-1 (2n-1 - (2n-1 mod n) = n)