/**
*    created: 2025-01-08 20:32:53
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
You are given two binary strings 
A
A and 
B
B, each of length 
N
N. Your task is to make your 
s
c
o
r
e
score odd which is initially 
0
0 by choosing 
N
N elements such that:

For each index 
i
i (
1
≤
i
≤
N
1≤i≤N), you will select either 
A
i
A 
i
​
  or 
B
i
B 
i
​
 .
If the character you select is equal to "1", add 
1
1 to the 
s
c
o
r
e
score. If the character is "0", add nothing.
Your goal is to determine whether it is possible to make the 
s
c
o
r
e
score an odd number. If it is possible, print YES, otherwise print NO.
*/
void pre_pro(){
}
vector<vector<int>> dp;

bool solve(int i, int sc, string &a, string &b) {
    if (i == a.size()) {
        return sc % 2 == 1;
    }

    if (dp[i][sc] != -1) {
        return dp[i][sc];
    }

    bool ch1 = solve(i + 1, sc + (a[i] == '1'), a, b);
    bool ch2 = solve(i + 1, sc + (b[i] == '1'), a, b);

    return dp[i][sc] = (ch1 || ch2);
}

void dxt(int test_case) {
    int n; 
    cin >> n;
    string a, b;
    cin >> a >> b;

    dp.assign(n, vector<int>(2 * n + 1, -1));

    if (solve(0, 0, a, b)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
