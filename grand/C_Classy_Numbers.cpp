/**
*    created: 2025-04-11 22:14:15
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
int dp[20][4][2];

int solve(int n){
    string s = to_string(n);
    int sz = s.size();
    memset(dp, -1, sizeof(dp));
    // lim, idx, non_zero, count, tight
    function<int(string&, int, int, bool)> find = [&](string &lim, int idx, int non_zero, bool tight){
        if(non_zero > 3) return 0;
        int sz = lim.size();
        if(idx == sz){
            return 1;
        }
        if(dp[idx][non_zero][tight] != -1) return dp[idx][non_zero][tight];
        
    };
    return find(0, -1, true);
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int l,r;
        cin >> l >> r;

        int ans = solve(r);
        ans -= solve(l - 1);
        show(ans);

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}