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
Problem Statement
You are given a simple connected undirected graph with 
N vertices and 
M edges, where vertices are numbered 
1 to 
N and edges are numbered 
1 to 
M. Edge 
i 
(1≤i≤M) connects vertices 
u 
i
​
  and 
v 
i
​
  bidirectionally and has weight 
w 
i
​
 .

For a path, define its weight as the maximum weight of an edge in the path. Define 
f(x,y) as the minimum possible path weight of a path from vertex 
x to vertex 
y.

You are given two sequences of length 
K: 
(A 
1
​
 ,A 
2
​
 ,…,A 
K
​
 ) and 
(B 
1
​
 ,B 
2
​
 ,…,B 
K
​
 ). It is guaranteed that 
A 
i
​
 

=B 
j
​
  
(1≤i,j≤K).

Permute the sequence 
B freely so that 
i=1
∑
K
​
 f(A 
i
​
 ,B 
i
​
 ) is minimized.

Constraints
2≤N≤2×10 
5
 
N−1≤M≤min( 
2
N×(N−1)
​
 ,2×10 
5
 )
1≤K≤N
1≤u 
i
​
 <v 
i
​
 ≤N 
(1≤i≤M)
1≤w 
i
​
 ≤10 
9
 
1≤A 
i
​
 ,B 
i
​
 ≤N 
(1≤i≤K)
The given graph is simple and connected.
All input values are integers.

*/
void pre_pro(){
}
void dxt(int test_case){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    rep(i, 0, m){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> a(k), b(k);
    rep(i, 0, k) cin >> a[i];
    rep(i, 0, k) cin >> b[i];
    vector<int> dist(n, INF);
    vector<int> vis(n, 0);
    set<pair<int, int>> s;
    s.insert({0, a[0] - 1});
    dist[a[0] - 1] = 0;
    while(!s.empty()){
        auto [d, u] = *s.begin();
        s.erase(s.begin());
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto [v, w] : g[u]){
            if(setmin(dist[v], max(d, w))){
                s.insert({dist[v], v});
            }
        }
    }
    int ans = 0;
    rep(i, 1, k){
        if(dist[b[i] - 1] == INF){
            cout << -1 << endl;
            return;
        }
        ans += dist[b[i] - 1];
    }
    cout << ans << endl;

}