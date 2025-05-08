/**
*    created: 2025-03-25 21:18:06
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

const int MOD = 998244353;

int mod_inv(int a, int m = MOD) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }
    return x < 0 ? x + m : x;
}

int mod_add(int a, int b) {
    return (a + b) % MOD;
}

int mod_sub(int a, int b) {
    return (a - b + MOD) % MOD;
}

int mod_mul(int a, int b) {
    return (a * b) % MOD;
}

int mod_div(int a, int b) {
    return mod_mul(a, mod_inv(b));
}

int mod_pow(int a, int p) {
    int result = 1;
    while (p > 0) {
        if (p & 1) result = mod_mul(result, a);
        a = mod_mul(a, a);
        p >>= 1;
    }
    return result;
}

const int maxn = 100100;
int fact[maxn], invf[maxn];

int C(int n, int r) {
    assert(n >= r && r >= 0);
    if (r == 0)
        return 1;
    return mod_mul(fact[n], mod_mul(invf[r], invf[n - r]));
}

void bincof(int a, int b) {
    fact[0] = 1;
    for (int i = 1; i <= maxn; ++i) {
        fact[i] = mod_mul(fact[i - 1], i);
        invf[i] = mod_inv(fact[i]);
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n, m, d;
        cin >> n >> m >> d;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        // dp[i][j] : number of ways to reach the top from row i, ending at column j (if that cell is a hold)
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<vector<int>> holds(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(a[i][j] == 'X')
                    holds[i].push_back(j);
            }
        }
        int maxd = 0;
        if(d * d - 1 >= 0){
            maxd = (int)floor(sqrtl((long double)d * d - 1));
        }
        
        if(!holds[n-1].empty()){
            sort(holds[n-1].begin(), holds[n-1].end());
            
            int sz = holds[n-1].size();
            for (int i = 0, p = 0; i < sz; i++){
                while(p < sz && holds[n-1][i] - holds[n-1][p] > d)
                    p++;
                int q = i;
                while(q < sz && holds[n-1][q] - holds[n-1][i] <= d)
                    q++;
                int cnt = q - p;
                dp[n-1][holds[n-1][i]] = cnt;
            }
        }
      
        for (int i = n - 2; i >= 0; i--){
            vector<int> pref(m + 1, 0);
            for (int j = 0; j < m; j++){
                pref[j+1] = mod_add(pref[j], dp[i+1][j]);
            }
           
            vector<int> diff(m+1, 0);
            vector<int>& curHolds = holds[i];
            if(!curHolds.empty()){
                sort(curHolds.begin(), curHolds.end());
                for (int f : curHolds) {
                    int lower_dp = max(0LL, f - maxd);
                    int upper_dp = min(m - 1, f + maxd);
                    int ways_contrib = mod_sub(pref[upper_dp + 1], pref[lower_dp]);
                    int left_bound = max(0LL, f - d);
                    int right_bound = min(m - 1, f + d);
                    diff[left_bound] = mod_add(diff[left_bound], ways_contrib);
                    diff[right_bound+1] = mod_sub(diff[right_bound+1], ways_contrib);
                }
                int cur = 0;
                for (int j = 0; j < m; j++){
                    cur = mod_add(cur, diff[j]);
                    dp[i][j] = mod_add(dp[i][j], cur);
                }
            }
        }
        
        int ways = 0;
        for (int j = 0; j < m; j++){
            ways = mod_add(ways, dp[0][j]);
        }
        cout << ways << "\n";
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}   
