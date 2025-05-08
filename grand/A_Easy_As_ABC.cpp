/**
*    created: 2025-03-02 00:40:44
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
const int N = 200200, INF = 8e18, MOD = 1000000007;

template <class T> bool setmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template <class T> bool setmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}

void dxt(int test_case);
void pre_pro();
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
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

void dxt(int test_case){
    int n = 3;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    set<string> ans;
    map<pair<int,int>, vector<pair<int,int>>> adj;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int x = -1; x <= 1; ++x){
                for(int y = -1; y <= 1; ++y){
                    if(x == 0 && y == 0) continue;
                    if(i + x >= 0 && i + x < n && j + y >= 0 && j + y < n){
                        adj[{i,j}].push_back({i + x, j + y});
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(auto &[x,y] : adj[{i,j}]){
                for(auto &[a,b] : adj[{x,y}]){
                    if(i != a || j != b){
                        string s = "";
                        s.push_back(grid[i][j]);
                        s.push_back(grid[x][y]);
                        s.push_back(grid[a][b]);
                        ans.insert(s);
                    }
                }
            }
        }
    }
    cout << *ans.begin() << endl;
}
