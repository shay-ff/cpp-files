/**
*    created: 2025-01-25 17:50:20
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
/*
You are given a grid of 
H rows and 
W columns.
Let 
(i,j) denote the cell at row 
i (
1≤i≤H) from the top and column 
j (
1≤j≤W) from the left.
The state of the grid is represented by 
H strings 
S 
1
​
 ,S 
2
​
 ,…,S 
H
​
 , each of length 
W, as follows:

If the 
j-th character of 
S 
i
​
  is #, cell 
(i,j) is painted black.
If the 
j-th character of 
S 
i
​
  is ., cell 
(i,j) is painted white.
If the 
j-th character of 
S 
i
​
  is ?, cell 
(i,j) is not yet painted.
Takahashi wants to paint each not-yet-painted cell white or black so that all the black cells form a rectangle.
More precisely, he wants there to exist a quadruple of integers 
(a,b,c,d) (
1≤a≤b≤H, 
1≤c≤d≤W) such that:

For each cell 
(i,j) (
1≤i≤H,1≤j≤W), if 
a≤i≤b and 
c≤j≤d, the cell is black;
otherwise, the cell is white.
*/
void pre_pro(){
}
void dxt(int test_case){
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,0,h) cin >> a[i];

    int l = INF, r = -INF, u = INF, d = -INF;
    rep(i,0,h){
        rep(j,0,w){
            if(a[i][j] == '#'){
                setmin(u, i);
                setmax(d, i);
                setmin(l, j);
                setmax(r, j);
            }
        }
    }
    debug(u, d, l, r);
    for(int i = u; i <= d; i++){
        for(int j = l; j <= r; j++){
            if(a[i][j] == '.'){
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";

}