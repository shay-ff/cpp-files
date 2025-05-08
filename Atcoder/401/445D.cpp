/**
*    created: 2025-04-13 09:35:38
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
// count integer in range [l,r] such that even position is even and odd position is a prime number {2,3,5,7}
bool isprime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0) return false;
    }
    return true;
}
int dp[20][2][2][2][2];
int solve(int pos, int even, int odd, int tight, int lead, int n){
    if(pos == n) return (even && odd);
    if(dp[pos][even][odd][tight][lead] != -1) return dp[pos][even][odd][tight][lead];
    int limit = (tight ? s[pos] - '0' : 9);
    int ans = 0;
    for(int i = 0; i <= limit; ++i){
        if(lead && i == 0) ans += solve(pos + 1, even, odd, tight && (i == limit), lead && (i == 0), n);
        else{
            ans += solve(pos + 1, even ^ (pos % 2 == 0), odd ^ (pos % 2 == 1 && isprime(i)), tight && (i == limit), false, n);
        }
    }
    return dp[pos][even][odd][tight][lead] = ans;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;
        
        memset(dp, -1, sizeof dp);
        int ans = solve(0, 0, 0, 1, 1, n);
        cout << ans << endl;
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}