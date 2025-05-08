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
Problem Statement
You are given an integer sequence of length 
N: 
A=(A 
1
​
 ,A 
2
​
 ,…,A 
N
​
 ).

You will perform the following consecutive operations just once:

Choose an integer 
x 
(0≤x≤N). If 
x is 
0, do nothing. If 
x is 
1 or greater, replace each of 
A 
1
​
 ,A 
2
​
 ,…,A 
x
​
  with 
L.

Choose an integer 
y 
(0≤y≤N). If 
y is 
0, do nothing. If 
y is 
1 or greater, replace each of 
A 
N
​
 ,A 
N−1
​
 ,…,A 
N−y+1
​
  with 
R.

Print the minimum possible sum of the elements of 
A after the operations.
*/
void pre_pro(){
}
void dxt(int test_case){
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];

    vector<int> prefx(n + 2, 1e18);
    prefx[0] = 0;
    rep(i, 1, n + 1) {
        prefx[i] = min(prefx[i - 1] + a[i], i * l);
    }
    vector<int> sufx(n + 2, 1e18);
    sufx[n + 1] = 0;
    rep(i,1,n + 1){
        sufx[i] = min(sufx[i + 1] + a[i], (n - i + 1) * r);
    }
    // debug(prefx);
    // debug(sufx);
    int ans = INF;
    rep(i,0,n + 1){
        ans = min(ans, prefx[i] + sufx[i + 1]);
    }

    show(ans);
}
