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

void pre_pro(){
}
/*
You are given a sequence 𝑎
, consisting of 𝑛
 integers, where the 𝑖
-th element of the sequence is equal to 𝑎𝑖
. You are also given two integers 𝑥
 and 𝑦
 (𝑥≤𝑦
).

A pair of integers (𝑖,𝑗)
 is considered interesting if the following conditions are met:

1≤𝑖<𝑗≤𝑛
;
if you simultaneously remove the elements at positions 𝑖
 and 𝑗
 from the sequence 𝑎
, the sum of the remaining elements is at least 𝑥
 and at most 𝑦
.
Your task is to determine the number of interesting pairs of integers for the given sequence 𝑎
.
*/
void dxt(int test_case){
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // x <= sum - a[i]- a[j] <= y
    // sum - y <= a[i] + a[j] <= sum - x

    int ans = 0, sum = accumulate(all(a), 0LL);
    sort(all(a));
    int lb = sum - y, ub = sum - x;
    for(int i = 0; i < n; ++i){
        int l = lb - a[i], h = ub - a[i];
        auto low = lower_bound(a.begin() + i + 1, a.end(), l);
        auto high = upper_bound(a.begin() + i + 1, a.end(), h);
        ans += (high - low);
    }
    show(ans);
}