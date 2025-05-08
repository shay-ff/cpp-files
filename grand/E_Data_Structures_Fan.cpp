/**
*    created: 2024-12-23 08:11:36
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
You are given an array of integers 𝑎1,𝑎2,…,𝑎𝑛
, as well as a binary string†
 𝑠
 consisting of 𝑛
 characters.

Augustin is a big fan of data structures. Therefore, he asked you to implement a data structure that can answer 𝑞
 queries. There are two types of queries:

"1 𝑙
 𝑟
" (1≤𝑙≤𝑟≤𝑛
) — replace each character 𝑠𝑖
 for 𝑙≤𝑖≤𝑟
 with its opposite. That is, replace all 𝟶
 with 𝟷
 and all 𝟷
 with 𝟶
.
"2 𝑔
" (𝑔∈{0,1}
) — calculate the value of the bitwise XOR of the numbers 𝑎𝑖
 for all indices 𝑖
 such that 𝑠𝑖=𝑔
. Note that the XOR
 of an empty set of numbers is considered to be equal to 0
.
Please help Augustin to answer all the queries!

For example, if 𝑛=4
, 𝑎=[1,2,3,6]
, 𝑠=𝟷𝟶𝟶𝟷
, consider the following series of queries:

"2 0
" — we are interested in the indices 𝑖
 for which 𝑠𝑖=𝟶
, since 𝑠=𝟷𝟶𝟶𝟷
, these are the indices 2
 and 3
, so the answer to the query will be 𝑎2⊕𝑎3=2⊕3=1
.
"1 1
 3
" — we need to replace the characters 𝑠1,𝑠2,𝑠3
 with their opposites, so before the query 𝑠=𝟷𝟶𝟶𝟷
, and after the query: 𝑠=𝟶𝟷𝟷𝟷
.
"2 1
" — we are interested in the indices 𝑖
 for which 𝑠𝑖=𝟷
, since 𝑠=𝟶𝟷𝟷𝟷
, these are the indices 2
, 3
, and 4
, so the answer to the query will be 𝑎2⊕𝑎3⊕𝑎4=2⊕3⊕6=7
.
"1 2
 4
" — 𝑠=𝟶𝟷𝟷𝟷
 →
 𝑠=𝟶𝟶𝟶𝟶
.
"2 1
" — 𝑠=𝟶𝟶𝟶𝟶
, there are no indices with 𝑠𝑖=𝟷
, so since the XOR
 of an empty set of numbers is considered to be equal to 0
, the answer to this query is 0
.
†
 A binary string is a string containing only characters 𝟶
 or 𝟷
.
*/
void pre_pro(){
}
void dxt(int test_case){
    int n;
    cin >> n;
    int a[n + 2];
    rep(i, 0, n) cin >> a[i + 1];
    string s; cin >> s;
    // rep(i, 1, n + 1) cout << a[i] << " ";
    // cout << endl;
    vector<int> pref(n + 2, 0);
    int oxor = 0, zxor = 0;
    for(int i = 1; i <= n; ++i){
        if(s[i - 1] == '0') zxor ^= a[i];
        else oxor ^= a[i];
        pref[i] = pref[i - 1] ^ a[i]; 
    }
    int q;
    cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l,r; cin >> l >> r;
            int xo = pref[r] ^ pref[l - 1];
            zxor ^= xo;
            oxor ^= xo;
        }
        else{
            int g;
            cin >> g;
            cout << ((g) ? oxor : zxor) << " ";
        }
    }
    cout << endl;
    
}