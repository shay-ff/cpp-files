/**
*    created: 2025-03-11 11:45:03
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
    cin >> T;
    for (int i = 1; i <= T; i++) {
        dxt(i);
    }
    return 0;
}

void pre_pro(){
}
void dxt(int test_case){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 1; i < n; ++i){
        int x; cin >> x;
        --x;
        adj[x].push_back(i);
    }
    string s;
    cin >> s;
    string col = "BW";
    vector<int> sub(n, 0);
    vector<vector<int>> dp(n, vector<int>(2, 0));
    function<void(int, int)> dfs = [&](int u, int p){
        sub[u] = 1;
        if(s[u] == col[0]) dp[u][0] = 1;
        else dp[u][1] = 1;
        for(int v : adj[u]){
            if(v == p) continue;
            dfs(v, u);
            sub[u] += sub[v];
            dp[u][0] += dp[v][0];
            dp[u][1] += dp[v][1];
        }
        
    };
    dfs(0, -1);
    debug(sub);
    debug(dp);
    int cntr = 0;
    for(int i = 0; i < n; ++i){
        if(dp[i][0] == 0 || dp[i][1] == 0) continue;
        cntr += (dp[i][0] == dp[i][1]);
    }
    cout << cntr << endl;
}