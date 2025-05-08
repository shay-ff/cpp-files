/**
*    created: 2025-03-02 14:17:23
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
Monocarp is playing yet another computer game. And yet again, his character is killing some monsters. There are 𝑛
 monsters, numbered from 1
 to 𝑛
, and the 𝑖
-th of them has 𝑎𝑖
 health points initially.

Monocarp's character has an ability that deals 𝑘
 damage to the monster with the highest current health. If there are several of them, the one with the smaller index is chosen. If a monster's health becomes less than or equal to 0
 after Monocarp uses his ability, then it dies.

Monocarp uses his ability until all monsters die. Your task is to determine the order in which monsters will die.
*/
void pre_pro(){
}
void dxt(int test_case){
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    vector<pair<int,int>> idx;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % k == 0){
            idx.push_back({k,i});
        }
        else{
            idx.push_back({a[i] % k,i});
        }
    }
    
    sort(all(idx), [&](pair<int,int> &a,  pair<int,int> &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    for(auto &x : idx) cout << x.second + 1 << " ";   
    cout << endl;

    


}