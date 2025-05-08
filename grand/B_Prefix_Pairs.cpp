/**
*    created: 2025-01-07 06:27:40
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

void pre_pro(){
}
struct Trie{
    Trie* child[26];
    int cnt;
    Trie(){
        cnt = 0;
        rep(i, 0, 26) child[i] = nullptr;
    }
};
void insert(Trie* root, string s){
    Trie* cur = root;
    for(char c : s){
        int id = c - 'a';
        if(!cur->child[id]) cur->child[id] = new Trie();
        cur = cur->child[id];
        cur->cnt++;
    }
}
int search(Trie* root, string s){
    Trie* cur = root;
    for(char c : s){
        int id = c - 'a';
        if(!cur->child[id]) return 0;
        cur = cur->child[id];
    }
    return cur->cnt;
}
/*
Given an array of strings 𝑤𝑜𝑟𝑑𝑠
, find the number of pairs where either the strings are equal or one string starts with another. In other words, find the number of such pairs 𝑖
, 𝑗
 (0≤𝑖<𝑗<𝑤𝑜𝑟𝑑𝑠.𝑙𝑒𝑛𝑔𝑡ℎ)
 that 𝑤𝑜𝑟𝑑𝑠[𝑖]
 is a prefix of 𝑤𝑜𝑟𝑑𝑠[𝑗]
, or 𝑤𝑜𝑟𝑑𝑠[𝑗]
 is a prefix of 𝑤𝑜𝑟𝑑𝑠[𝑖]
.
*/
void dxt(int test_case){
    int n; cin >> n;
    vector<string> a(n);
    rep(i, 0, n) cin >> a[i];
    int ans = 0;
    Trie* root = new Trie();
    rep(i, 0, n){
        ans += search(root, a[i]);
        insert(root, a[i]);
    }
    cout << ans << endl;

}