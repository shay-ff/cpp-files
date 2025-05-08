/**
*    created: 2024-12-28 17:37:05
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
There is a calculator with the buttons 00, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.
When a string 
x is displayed on this calculator and you press a button 
b, the resulting displayed string becomes the string 
x with 
b appended to its end.

Initially, the calculator displays the empty string (a string of length 
0).
Find the minimum number of button presses required to display the string 
S on this calculator.


*/
void pre_pro(){
}
void dxt(int test_case){
    string s;
    cin >> s;
    int n = sz(s);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] != '0'){
            ans ++;
        }
        else{
            if(i + 1 < n && s[i + 1] == '0'){
                ans++;
                i++;
            }
            else ans++;
        }
    }
    show(ans);

}