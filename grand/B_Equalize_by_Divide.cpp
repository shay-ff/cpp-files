/**
*    created: 2025-03-02 03:58:13
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
You are given an array 𝑎1,𝑎2,…,𝑎𝑛
 of positive integers.

You can make this operation multiple (possibly zero) times:

Choose two indices 𝑖
, 𝑗
 (1≤𝑖,𝑗≤𝑛
, 𝑖≠𝑗
).
Assign 𝑎𝑖:=⌈𝑎𝑖𝑎𝑗⌉
. Here ⌈𝑥⌉
 denotes 𝑥
 rounded up to the smallest integer ≥𝑥
.
Is it possible to make all array elements equal by some sequence of operations (possibly empty)? If yes, print any way to do it in at most 30𝑛
 operations.

It can be proven, that under the problem constraints, if some way exists to make all elements equal, there exists a way with at most 30𝑛
 operations.
*/
void pre_pro(){
}
void dxt(int test_case){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<pair<int,int>> ans;
    

}