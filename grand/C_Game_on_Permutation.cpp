/**
*    created: 2025-03-03 16:47:41
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

void pre_pro(){
}
/*
1 2
2 3
3 4
3 5
1 6
6 7
7 8

u = 1;


1 -> 2 , 6
2 -> 1 , 3
3 -> 2 , 4 , 5
4 -> 3
5 -> 3
6 -> 1 , 7
7 -> 6 , 8
8 -> 7

{currNode, currDist}

*/
void dxt(int test_case){
    int edgescount, nodes;
    cin >> edgescount >> nodes;

    vector<vector<int>> adj(nodes + 1);
    for(int i = 0; i < edgescount; ++i){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int u; cin >> u;

    vector<int> vis(nodes + 1, 0);
    queue<pair<int,int>> q;
    q.push({u, 0});
    vector<pair<int,int>> pr;
    while(!q.empty()){
        auto [currNode, currDist] = q.front();
        q.pop();
        vis[currNode] = 1;
        pr.push_back({currNode, currDist});
        for(auto &child : adj[currNode]){
            if(!vis[child]){
                q.push({child, currDist + 1});
            }
        }
    }
    for(auto &x : pr){
        cout << x.first << " " << x.second << endl;
    }
    

}