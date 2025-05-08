/**
*    created: 2025-02-26 20:06:44
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
/*
You are standing in a queue that is infinitely long, waiting to get tickets for various events during Technex.
The ticket distribution follows these rules:

Every second, tickets are given to the 
1
s
t
1 
st
  and 
3
r
d
3 
rd
  persons in the queue.
After receiving their tickets, those people leave the queue.
The person who was originally in the 
2
n
d
2 
nd
  position (before the 
1
s
t
1 
st
  and 
3
r
d
3 
rd
  people left) moves up to the 
1
s
t
1 
st
  position.
This process repeats every second, with the 
1
s
t
1 
st
  and 
3
r
d
3 
rd
  persons receiving tickets and leaving.
Initially, you are at position 
N
N in the queue.

Determine after how many seconds you will get the tickets.
*/
void dxt(int test_case){
    int n;
    cin >> n;
    int ans = 0;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    if(n & 1){
        cout << n/2 << endl;
    }
    else{
        cout << n/2 + 1 << endl;
    }
}