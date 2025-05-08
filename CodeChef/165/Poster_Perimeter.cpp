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
    cin >> T;
    for (int i = 1; i <= T; i++) {
        dxt(i);
    }
    return 0;
}
/*
Chef wants to print out a poster on a rectangular piece of paper.

The piece of paper he uses cannot be too large, or his printer will be unable to handle it.
Specifically, the length of the rectangle must be an integer between 
1
1 and 
N
N units, and the width must be an integer between 
1
1 and 
M
M units.

Chef would like it if the perimeter of the paper is as close to 
K
K as possible.
If Chef chooses the paper's dimensions optimally, find the minimum possible difference between the paper's perimeter and 
K
K.

Recall that the perimeter of a rectangle with length 
l
l and width 
w
w equals 
2
⋅
(
l
+
w
)
2⋅(l+w).
*/
void pre_pro(){
}
void dxt(int test_case){
    int n, m, k;
    cin >> n >> m >> k;
    int ans = INF;
    set<int> st;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int p = 2  * (i + j);
            st.insert(p);
        }
    }
    for(auto x : st){
        setmin(ans, abs(x - k));
    }
    show(ans);
}