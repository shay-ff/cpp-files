/**
*    created: 2025-02-09 20:34:34
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
With the approach of Valentine's Day, Skibidus desperately needs a way to rizz up his crush! Fortunately, he knows of just the way: creating the perfect Binary String!

Given a binary string∗
 𝑡
, let 𝑥
 represent the number of 𝟶
 in 𝑡
 and 𝑦
 represent the number of 𝟷
 in 𝑡
. Its balance-value is defined as the value of max(𝑥−𝑦,𝑦−𝑥)
.

Skibidus gives you three integers 𝑛
, 𝑚
, and 𝑘
. He asks for your help to construct a binary string 𝑠
 of length 𝑛+𝑚
 with exactly 𝑛
 𝟶
's and 𝑚
 𝟷
's such that the maximum balance-value among all of its substrings†
 is exactly 𝑘
. If it is not possible, output -1.
*/
void pre_pro(){
}
void dxt(int test_case){
    int n,m,k;
    cin >> n >> m >> k;

    int x = 0, y = 0;
    string s;
    rep(i,0,n+m){
        if(i%2 == 0){
            if(x < n){
                s += '0';
                x++;
            }else{
                s += '1';
                y++;
            }
        }else{
            if(y < m){
                s += '1';
                y++;
            }else{
                s += '0';
                x++;
            }
        }
    }
    cout << s << endl;
}