/**
*    created: 2025-04-13 21:24:21
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
        vector<string> ar(3);
        for(int i = 0; i < 3; ++i){
            cin >> ar[i];
        }
        string ans = "";
        for(int i = 0; i < 3; ++i){
            ans += ar[i][0];
        }
        cout << ans << endl;
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}