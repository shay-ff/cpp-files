/**
*    created: 2024-12-28 17:43:32
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
There is an 
N×N grid. Takahashi wants to color each cell black or white so that all of the following conditions are satisfied:

For every row, the following condition holds:
There exists an integer 
i (0≤i≤N) such that the leftmost 
i cells are colored black, and the rest are colored white.
For every column, the following condition holds:
There exists an integer 
i (0≤i≤N) such that the topmost 
i cells are colored black, and the rest are colored white.
Out of these 
N 
2
  cells, 
M of them have already been colored. Among them, the 
i-th one is at the 
X 
i
​
 -th row from the top and the 
Y 
i
​
 -th column from the left, and it is colored black if 
C 
i
​
  is B and white if 
C 
i
​
  is W.

Determine whether he can color the remaining uncolored 
N 
2
 −M cells so that all the conditions are satisfied.
*/

void pre_pro(){
}
void dxt(int test_case){
    int n,m;
    cin >> n >> m;

    map<pair<int,int>,char> mp;
    rep(i,0,m){
        int x,y;
        char c;
        cin >> x >> y >> c;
        mp[{x,y}] = c;
    }
    // if there happens to be a W before a B in the same colomn than its a no
    // if there happens to be a W before a B in the same row than its a no

    

}