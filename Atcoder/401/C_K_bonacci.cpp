/**
*    created: 2025-04-12 17:32:11
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
/*
You are given positive integers 
N and 
K. Define a sequence 
A=(A 
0
​
 ,A 
1
​
 ,…,A 
N
​
 ) of length 
N+1 as follows:

A 
i
​
 =1 for 
0≤i<K;
A 
i
​
 =A 
i−K
​
 +A 
i−K+1
​
 +…+A 
i−1
​
  for 
K≤i.
Find 
A 
N
​
  modulo 
10 
9
 .


*/
const int MOD = 1e9;
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n, k;
        cin >> n >> k;

        vector<int> dp(n + 1, 0);
        int sum = 0;

        for (int i = 0; i < k && i <= n; ++i) {
            dp[i] = 1;
            sum = (sum + dp[i]) % MOD;
        }

        for (int i = k; i <= n; ++i) {
            dp[i] = sum;
            sum = (sum + dp[i] - dp[i - k] + MOD) % MOD;
        }

        cout << dp[n] << '\n';
    };
    int T = 1;
    // cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}