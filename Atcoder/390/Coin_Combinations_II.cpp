/**
*    created: 2025-01-26 14:58:05
**/
#include<bits/stdc++.h>
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

#define int long long
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define rrep(i, a, b) for(int i = a; i >= b; --i)

// order_of_key (k) : Number of items strictly smaller than k.
// find_by_order(k) : K-th element in a set (counting from zero).
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009, 1000000023, 1000000007, 998244353

template <class T> bool setmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template <class T> bool setmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}

void dxt(int test_case);
void pre_pro();
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    pre_pro();
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        dxt(i);
    }
    return 0;
}

int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                dp[i][j] = matrix[i][j] - '0';
                if(i > 0) dp[i][j] += dp[i - 1][j];
                if(j > 0) dp[i][j] += dp[i][j - 1];
                if(i > 0 and j > 0) dp[i][j] -= dp[i - 1][j - 1];
            }
        } 
        // for(int i = 0; i < n; ++i){
        //     for(int j = 0; j < m; ++j){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        auto check = [&](int mid){
            int ans = 0;
            for(int i = 0; i + mid - 1 < n; ++i){
                for(int j = 0; j + mid - 1 < m; ++j){
                    int sum = dp[i + mid - 1][j + mid - 1];
                    if(i > 0) sum -= dp[i - 1][j + mid - 1];
                    if(j > 0) sum -= dp[i + mid - 1][j - 1];
                    if(i > 0 and j > 0) sum += dp[i - 1][j - 1];
                    setmax(ans, sum);
                }
            }
            return ans >= mid * mid;
        };
        int low = 0, high = 201;
        int ans = high;
        while(low <= high){
            int mid = (low + high)/2;
            if(check(mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        } 
        return ans;
        return 6;
    }
void pre_pro(){
}
void dxt(int test_case){
    int n,x;
    cin >> n >> x;
    vector<int> dp(x + 1, 0), coins(n);
    for(auto &i : coins) cin >> i;
    dp[0] = 1;
    for(auto &c : coins){
        for(int i = 1; i  <=x; ++i){
            if(i - c >= 0){
                dp[i] = dp[i] + dp[i - c];
            }
        }
    }
    debug(dp);
    show(dp[x]);
    // write code to find 2d prefix sum for matrix
    vector<vector<int>> dp(n, vector<int>(m,0));
    // say there is some matrix : matrix

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            dp[i][j] = matrix[i][j];
            if(i > 0) dp[i][j] += dp[i - 1][j];
            if(j > 0) dp[i][j] += dp[i][j - 1];
            if(i > 0 and j > 0) dp[i][j] -= dp[i - 1][j - 1];
        }
    }
}