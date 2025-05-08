// /**
// *    Count of the numbers having sum of digits equal to x.
// **/
// #include<bits/stdc++.h>
// using namespace std;
// #ifndef ONLINE_JUDGE
// #include "../debug.cpp"
// #else
// #define debug(...)
// #define debugArr(...)
// #endif
// #define int long long
// #define show(x) cout << x << endl
// #define sz(x) (int)(x.size())
// // 18 * 9 = 
// count of numbers having sum of digits equal to x
// int dp[20][165][2];

// int solve(string &s, int idx, int curr, int sum, int tight) {
//     if (curr > sum) return 0;
//     if (idx == s.size()) return curr == sum;
//     if (dp[idx][curr][tight] != -1) return dp[idx][curr][tight];
    
//     int ans = 0;
//     int ub = tight ? s[idx] - '0' : 9;
//     for (int i = 0; i <= ub; ++i) {
//         int next_tight = (tight && (i == ub)) ? 1 : 0;
//         ans += solve(s, idx + 1, curr + i, sum, next_tight);
//     }
    
//     return dp[idx][curr][tight] = ans;
// }

// signed main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     auto solve_test = [&](int test_case) {
//         int l, r, x;
//         cin >> l >> r >> x;
//         memset(dp, -1, sizeof(dp));
//         string _r = to_string(r), _l = to_string(l - 1);
//         while (_l.size() < _r.size()) _l = '0' + _l;
//         int ans = solve(_r, 0, 0, x, 1);
//         memset(dp, -1, sizeof(dp));
//         int ans2 = solve(_l, 0, 0, x, 1);
//         cout << ans << endl;
//     };
//     int T = 1;
//     // cin >> T;
//     for (int i = 0; i < T; ++i) {
//         solve_test(i);
//     }
// }
/**
*       created: 2025-04-11 03:30:58
*       
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
const int MOD = 1e9 + 7;
int dp[20][165][2]; // state : digit position, sum of digits, tight
int solve(string &lim, int idx, int sum, int d, bool tight){
    if(idx == sz(lim)){
        return sum % d == 0;
    }
    if(dp[idx][sum][(int)tight] != -1)
        return dp[idx][sum][(int)tight];
    int ans = 0, ub = tight ? lim[idx] - '0' : 9;
    for(int i = 0; i <= ub; ++i){
        ans += solve(lim, idx + 1, sum + i, d, tight && (i == ub));
    }
    return dp[idx][sum][(int)tight] = ans % MOD;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int k,d;
        cin >> k >> d;
        memset(dp, -1, sizeof(dp));
        string _k = to_string(k);
        int ans = solve(_k, 0, 0, d, true);
        show(ans - 1);
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}