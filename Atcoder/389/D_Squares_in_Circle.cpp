/**
*    created: 2025-01-18 17:44:10
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
On the two-dimensional coordinate plane, there is an infinite tiling of 
1×1 squares.

Consider drawing a circle of radius 
R centered at the center of one of these squares. How many of these squares are completely contained inside the circle?

More precisely, find the number of integer pairs 
(i,j) such that all four points 
(i+0.5,j+0.5), 
(i+0.5,j−0.5), 
(i−0.5,j+0.5), and 
(i−0.5,j−0.5) are at a distance of at most 
R from the origin.


*/
void pre_pro(){
}
int64_t f(int64_t n) {
    int64_t sum = 0;

    for (int64_t k = 1; k < n; ++k) {
        double inner_value = sqrt(n * n - (k + 0.5) * (k + 0.5)) - 0.5;
        sum += static_cast<int64_t>(floor(inner_value));
    }
    return 4 * sum + 4 * n - 3;
}
void dxt(int test_case){
    int R; cin >> R;
    cout << f(R) << endl;
}