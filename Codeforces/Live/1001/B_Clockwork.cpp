/**
*    created: 2025-01-26 20:08:14
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
/*
You have a sequence of 𝑛
 time clocks arranged in a line, where the initial time on the 𝑖
-th clock is 𝑎𝑖
. In each second, the following happens in order:

Each clock's time decreases by 1
. If any clock's time reaches 0
, you lose immediately.
You can choose to move to an adjacent clock or stay at the clock you are currently on.
You can reset the time of the clock you are on back to its initial value 𝑎𝑖
.
Note that the above events happen in order. If the time of a clock reaches 0
 in a certain second, even if you can move to this clock and reset its time during that second, you will still lose.

You can start from any clock. Determine if it is possible to continue this process indefinitely without losing.
*/
void pre_pro(){
}
void dxt(int test_case){
    int n,T;
    cin >> n;

    vector<int> a(n);
    rep(i,0,n) cin >> a[i];

    // i should be able to reach far end and come back to i in time for condition to be fulfilled
    bool ok = true;
    for(int i = 0; i < n; ++i){
        int d =  i;
        int d2 =  (n - i - 1);
        d = max(d, d2);
        d *= 2;
        ok &= !(d >= a[i]);
    }
    yesno(ok);
}