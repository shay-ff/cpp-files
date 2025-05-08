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
You are given 
N strings 
S 
1
​
 ,S 
2
​
 ,…,S 
N
​
  consisting of lowercase English alphabets.

Consider choosing some number of strings from 
S 
1
​
 ,S 
2
​
 ,…,S 
N
​
 .

Find the maximum number of distinct alphabets that satisfy the following condition: "the alphabet is contained in exactly 
K of the chosen strings."
*/
void pre_pro(){
}
void dxt(int test_case){
    int n,k;
    cin >> n >> k;
    vector<string> ar(n);
    for(auto &s : ar){
        cin >> s;
    }
    vector<int> cnt(26, 0);
    for(auto &s : ar){
        vector<int> temp(26, 0);
        for(auto &c : s){
            temp[c - 'a'] = 1;
        }
        rep(i,0,26){
            cnt[i] += temp[i];
        }
    }
    int ans = 0;
    rep(i,0,26){
        if(cnt[i] >= k){
            ans++;
        }
    }
    show(ans);
}