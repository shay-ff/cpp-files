/**
*    created: 2025-01-29 20:01:40
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
Toofan is playing an exciting game where there are 
N
N rings, and for each ring, Toofan can either SWISH or PASS. The goal of the game is to achieve at least 
K
K swishes.

The game will end immediately when at least one of the following two conditions is met:

Toofan has finished all the 
N
N rings; or
It it impossible to win the game any more.
This means it is impossible for Toofan to get at least 
K
K swishes, regardless of what he does with the remaining rings.
Toofan knows the value of 
K
K (the number of swishes he must achieve), and remembers the sequence of moves he made. However, he no longer remembers the value of 
N
N (the total number of rings).
You are given a string 
S
S of length 
M
M, denoting the moves Toofan made during the game. Each character of 
S
S is either S (denoting a swish) or P (denoting a pass).

Given that Toofan ended the game after exactly this sequence of 
M
M moves, what could the value of 
N
N be?


*/
void pre_pro(){
}
void dxt(int test_case){
    int m,k;
    cin >> m >> k;
    string s;
    cin >> s;

    int n = 0;
    int swish = 0;
    for(int i = 0; i < m; ++i){
        if(s[i] == 'S') swish++;
        else n++;
    }
    debug(swish);
    if(swish >= k){
        cout << m << endl;
        return;
    }
    int moves = m + (k - swish);
    cout << moves - 1 << endl;


}