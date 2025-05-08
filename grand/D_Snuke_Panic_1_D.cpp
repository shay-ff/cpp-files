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

#define int int64_t
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define rrep(i, a, b) for(int i = a; i >= b; --i)

//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
typedef long double lld;
using ull = unsigned long long;
const int INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

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

void pre_pro(){
}
using tuple = tuple<int, int, int>;
void dxt(int test_case){
    int n;
    cin >> n;
    const int N = 100100;
    int x[N] = {0}, a[N] = {0};
    for(int i = 0; i < n; ++i){
        int t,xi, ai;
        cin >> t >> xi >> ai;
        x[t] = xi;
        a[t] = ai;
    }
    vector<vector<int>> dp(N, vector<int>(5, -INF));

    rep(i, 0, N){
        if(i == 0){
            dp[0][0] = 0;
            if(x[i] == 0){
                dp[0][0] += a[0];
                continue; 
            }
        }
        rep(j, 0, 5){
            if(j > 0){
            setmax(dp[i][j], dp[i - 1][j - 1]);
            }
            setmax(dp[i][j], dp[i - 1][j]);
            if(j < 4){
                setmax(dp[i][j], dp[i - 1][j + 1]);
            }
            if(dp[i][j] == -INF){
                continue;
            }
            if(j == x[i]){
                dp[i][j] += a[i];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 5; ++i){
        // debug(dp[N - 1][i]);
        setmax(ans, dp[N - 1][i]);
    }
    cout << ans;
}