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
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

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
/*
There is a grid with 
N×N squares. We denote by 
(i,j) the square at the 
i-th row from the top and 
j-th column from the left.

Initially, a piece is placed on 
(1,1). You may repeat the following operation any number of times:

Let 
(i,j) be the square the piece is currently on. Move the piece to the square whose distance from 
(i,j) is exactly 
M
​
 .
Here, we define the distance between square 
(i,j) and square 
(k,l) as 
(i−k) 
2
 +(j−l) 
2
 
​
 .

For all squares 
(i,j), determine if the piece can reach 
(i,j). If it can, find the minimum number of operations required to do so.


*/
void pre_pro(){
}
void dxt(int test_case){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(n, INF));
    dp[0][0] = 0;
    rep(i,0,n){
        rep(j,0,n){
            if(i + 1 < n){
                setmin(dp[i + 1][j], dp[i][j] + 1);
            }
            if(j + 1 < n){
                setmin(dp[i][j + 1], dp[i][j] + 1);
            }
            if(i + 1 < n && j + 1 < n){
                setmin(dp[i + 1][j + 1], dp[i][j] + 1);
            }
            if(i + m < n){
                setmin(dp[i + m][j], dp[i][j] + 1);
            }
            if(j + m < n){
                setmin(dp[i][j + m], dp[i][j] + 1);
            }
            if(i + m < n && j + m < n){
                setmin(dp[i + m][j + m], dp[i][j] + 1);
            }
        }
    }
    rep(i,0,n){
        rep(j,0,n){
            if(dp[i][j] == INF){
                cout << -1 << " ";
            }
            else{
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }
}