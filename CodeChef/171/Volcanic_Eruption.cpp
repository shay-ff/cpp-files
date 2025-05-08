/**
*    created: 2025-01-29 20:42:11
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
template <class T> T floor_div(T x, T y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x >= 0) return x / y;
    return (x + 1) / y - 1;
}

template <class T> T ceil_div(T x, T y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x <= 0) return x / y;
    return (x - 1) / y + 1;
}
/*
There are 
N
N positions along a line, each of which contains either a building (with positive height) or a volcano.
You are given this information as an array 
A
A of length 
N
N, where 
A
i
=
0
A 
i
​
 =0 represents a volcano at position 
i
i, and 
A
i
>
0
A 
i
​
 >0 represents a building with height 
A
i
A 
i
​
  at position 
i
i.

Initially, the lava level is 
0
0. Every second, all the volcanoes erupt simultaneously, increasing each of their lava levels by exactly 
P
P.
Lava behaves as follows:

Suppose the current lava level is 
X
X. Then, lava will flow left and and right from each volcano till it reaches a building whose height is strictly greater than 
X
X, at which point it will stop flowing.
For each 
i
i, determine the minimum time at which building 
i
i is completely submerged under lava.
*/
void pre_pro(){
}
void dxt(int test_case){
    int n,k;
    cin >> n >> k;

    vector<int> ar(n);
    for(int &i : ar){
        cin >> i;
    }   
    vector<int> closeL(n, -1), closeR(n, n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() and ar[st.top()] < ar[i]){
            closeR[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() and ar[st.top()] < ar[i]){
            closeL[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        int l = closeL[i], r = closeR[i];
        int left = i - l, right = r - i;
        int leftTime = (left + k - 1) / k;
        int rightTime = (right + k - 1) / k;
        ans[i] = max(leftTime, rightTime);
    }
    for(int i : ans){
        cout << i << ' ';
    }
    cout << endl;
    
}