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
There are n sharks who grow flowers for Wet Shark. They are all sitting around the table, such that sharks i and i + 1 are neighbours for all i from 1 to n - 1. Sharks n and 1 are neighbours too.

Each shark will grow some number of flowers si. For i-th shark value si is random integer equiprobably chosen in range from li to ri. Wet Shark has it's favourite prime number p, and he really likes it! If for any pair of neighbouring sharks i and j the product si·sj is divisible by p, then Wet Shark becomes happy and gives 1000 dollars to each of these sharks.

At the end of the day sharks sum all the money Wet Shark granted to them. Find the expectation of this value.

Input
The first line of the input contains two space-separated integers n and p (3 ≤ n ≤ 100 000, 2 ≤ p ≤ 109) — the number of sharks and Wet Shark's favourite prime number. It is guaranteed that p is prime.

The i-th of the following n lines contains information about i-th shark — two space-separated integers li and ri (1 ≤ li ≤ ri ≤ 109), the range of flowers shark i can produce. Remember that si is chosen equiprobably among all integers from li to ri, inclusive.
*/
void pre_pro(){
}
void dxt(int test_case){
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> v(n);
    rep(i, 0, n) cin >> v[i].first >> v[i].second;
    int ans = 0;
    
    cout << fixed << setprecision(10) << (double)ans / n;
}