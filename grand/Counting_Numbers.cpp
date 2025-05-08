/**
*    created: 2025-04-11 03:35:29
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
int dp[20][2][2];
int find(string &lim, int idx, int prev, bool tight, bool leading_zeroes){
    int sz = lim.size();
    if(idx == sz && f){
        return 1;
    }
}
int solve(int n){
    memset(dp, -1, sizeof(dp));
    string s = to_string(n);
    
    int res = find(s, 0, -1, true, true);
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int a,b;
        cin >> a >> b;
        int ans = solve(a);
        ans -= solve(b - 1);
        show(ans);
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}