#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long int;
const int MOD = 998244353;
const int maxm = 1000001;

vector<int> make() {
    vector<int> spf(maxm);
    for(int i = 0; i < maxm; i++) {
        spf[i] = i;
    }
    for(int i = 2; i * i < maxm; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j < maxm; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

set<int> factor(int num, const vector<int>& spf) {
    set<int> factors;
    while(num > 1) {
        factors.insert(spf[num]);
        num /= spf[num];
    }
    return factors;
}
void dxt() {
    int n;
    cin >> n;
    
    vector<int> ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    
    vector<int> spf = make();
    
    vector<vector<int>> adj(n);
    vector<set<int>> factors(n);
    
    for(int i = 0; i < n; i++) {
        factors[i] = factor(ar[i], spf);
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            bool ok = false;
            for(int f : factors[i]) {
                if(factors[j].count(f)) {
                    ok = true;
                    break;
                }
            }
            if(ok) {
                adj[i].push_back(j);
            }
        }
    }
    
    vector<ll> dp(n, 0);
    dp[0] = 1;
    
    for(int i = 0; i < n; i++) {
        if(dp[i] == 0) continue;
        for(int u : adj[i]) {
            dp[u] = (dp[u] + dp[i]) % MOD;
        }
    }
    
    cout << dp[n-1] << endl;
}

int main() {
    int t =1 ;
    // cin >> t;
    while (t--) {
        dxt();
    }
}
