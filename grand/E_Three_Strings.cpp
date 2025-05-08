/**
*    created: 2024-12-23 07:51:30
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
You are given three strings: 𝑎
, 𝑏
, and 𝑐
, consisting of lowercase Latin letters. The string 𝑐
 was obtained in the following way:

At each step, either string 𝑎
 or string 𝑏
 was randomly chosen, and the first character of the chosen string was removed from it and appended to the end of string 𝑐
, until one of the strings ran out. After that, the remaining characters of the non-empty string were added to the end of 𝑐
.
Then, a certain number of characters in string 𝑐
 were randomly changed.
For example, from the strings 𝑎=abra
 and 𝑏=cada
, without character replacements, the strings caabdraa
, abracada
, acadabra
 could be obtained.

Find the minimum number of characters that could have been changed in string 𝑐
.
*/
void pre_pro(){
}
void dxt(int test_case){
    string a,b,c;
    cin >> a >> b >> c;
    int n = sz(a);
    int m = sz(b);
    int k = sz(c);

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    rep(i, 0, n + 1){
        rep(j, 0, m + 1){
            if(i == 0 && j == 0) continue;
            if(i == 0){
                dp[i][j] = dp[i][j - 1] + (b[j - 1] != c[i + j - 1]);
            }else if(j == 0){
                dp[i][j] = dp[i - 1][j] + (a[i - 1] != c[i + j - 1]);
            }else{
                dp[i][j] = min(dp[i - 1][j] + (a[i - 1] != c[i + j - 1]), dp[i][j - 1] + (b[j - 1] != c[i + j - 1]));
            }
        }
    }
    show(dp[n][m]);
}