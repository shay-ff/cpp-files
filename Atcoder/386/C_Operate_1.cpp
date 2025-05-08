/**
*    created: 2024-12-28 17:38:55
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
Determine whether it is possible to perform the following operation on string 
S between 
0 and 
K times, inclusive, to make it identical to string 
T.

Choose one of the following three operations and execute it.
Insert any one character at any position in 
S (possibly the beginning or end).
Delete one character from 
S.
Choose one character in 
S and replace it with another character.

*/
bool solve(string &s, string &t){
    if (s == t) return true;
    
    int n = s.length();
    int m = t.length();
    
    if (abs(n - m) > 1) return false;
    
    if (n == m) {
        int diff = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                diff++;
                if (diff > 1) return false;
            }
        }
        return true;
    }

     string shorter = (n < m) ? s : t;
     string longer = (n < m) ? t : s;
    
    int i = 0;
     int sn = shorter.length();
    
    while (i < sn && shorter[i] == longer[i]) {
        i++;
    }
    
    while (i < sn) {
        if (shorter[i] != longer[i + 1]) return false;
        i++;
    }
    
    return true;

}
void pre_pro(){
}
void dxt(int test_case){
    int k; cin >> k;
    string s,t;
    cin >> s >> t;

    cout << ((solve(s,t)) ? "Yes" : "No") << endl;
}