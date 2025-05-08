/**
*    created: 2025-01-07 06:31:09
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
Suppose there is a grid consisting of an infinite number of cells and you are standing on cell (0,0)
.

Let your move strength be 𝐾
 which is initially set to 1
. In one move you can perform the following operations:

Move horizontally i.e. (𝑥+𝑘,𝑦)
 from (𝑥,𝑦)
.
Move vertically i.e. (𝑥,𝑦+𝑘)
 from (𝑥,𝑦)
.
Increase the value of 𝐾
 by 1
.
Find and print the minimum number of moves to reach the destination cell represented by (𝑎,𝑏)
.
*/

void pre_pro(){
}
void dxt(int test_case){
    int x,y;
    cin >> x >> y;
    int ans = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    map<pair<int,int>,int> vis;
    vis[{0,0}] = 1;
    int k = 1;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto [a,b] = q.front();
            q.pop();
            if(a == x && b == y){
                cout << ans << endl;
                return;
            }
            q.push({a + k,b});
            q.push({a - k,b});
            q.push({a,b + k});
            q.push({a,b - k});
            q.push({a + k,b + k});
            q.push({a - k,b - k});
            q.push({a + k,b - k});
            q.push({a - k,b + k});
        }
        k++;
        ans++;
    }
    
}