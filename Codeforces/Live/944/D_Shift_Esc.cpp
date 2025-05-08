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

//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
typedef long double lld;
using ull = unsigned long long;
const int N = 222, INF = 2e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

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
/*
You are given a grid with 𝑛
 rows and 𝑚
 columns of non-negative integers and an integer 𝑘
. Let (𝑖,𝑗)
 denote the cell in the 𝑖
-th row from the top and 𝑗
-th column from the left (1≤𝑖≤𝑛
, 1≤𝑗≤𝑚
). For every cell (𝑖,𝑗)
, the integer 𝑎𝑖,𝑗
 is written on the cell (𝑖,𝑗)
.

You are initially at (1,1)
 and want to go to (𝑛,𝑚)
. You may only move down or right. That is, if you are at (𝑖,𝑗)
, you can only move to (𝑖+1,𝑗)
 or (𝑖,𝑗+1)
 (if the corresponding cell exists).

Before you begin moving, you may do the following operation any number of times:

Choose an integer 𝑖
 between 1
 and 𝑛
 and cyclically shift row 𝑖
 to the left by 1
. Formally, simultaneously set 𝑎𝑖,𝑗
 to 𝑎𝑖,(𝑗mod𝑚)+1
 for all integers 𝑗
 (1≤𝑗≤𝑚
).
Note that you may not do any operation after you start moving.
After moving from (1,1)
 to (𝑛,𝑚)
, let 𝑥
 be the number of operations you have performed before moving, and let 𝑦
 be the sum of the integers written on visited cells (including (1,1)
 and (𝑛,𝑚)
). Then the cost is defined as 𝑘𝑥+𝑦
.

Find the minimum cost to move from (1,1)
 to (𝑛,𝑚)
.
*/
const int maxm = 220;
int dp[maxm][maxm][maxm];

// dp[i][j][k] = minimum cost to reach (i, j) with k operations
int solve(int i, int j, int op, vector<vector<int>> &a, int n, int m){
    if(i == n and j == m){
        return 0;
    }
    if(i > n or j > m){
        return INF;
    }
    if(dp[i][j][op] != -1){
        return dp[i][j][op];
    }
    int ans = INF;
    if(j != m - 1){
        setmin(ans, a[i][j] + solve(i, j + 1, op, a, n, m));
    }
    if(i != n - 1){
        rep(p, 0, m){
            int x = (j + p) % m;
            setmin(ans, (a[i + 1][(j + p) % m] + solve(i + 1, j, op + abs(op - x) + 1, a, n, m)));
        }
    }
    return dp[i][j][op] = ans;
}
void pre_pro(){
}
void dxt(int test_case){
    int n,m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> a(n, vector<int>(m));
    rep(i,0,n){
        rep(j,0,m){
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof dp);
    int ans = solve(0, 0, 0, a, n - 1, m - 1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << dp[i][j][k] << " ";
        }
        cout << endl;
    }
    
    
}