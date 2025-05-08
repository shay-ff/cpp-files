/**
*    created: 2025-01-17 20:26:06
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
void dxt(int test_case){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<string> str(n);
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        str[i] = s;
        for(int j = 0; j < s.size(); ++j){
            if(s[j] == '1'){
                adj[i].push_back(j);
            }
        }
    }
    int cntr = 0;
    for(int i = 0; i < n; ++i){
        if(adj[i].size()) cntr++;
    }
    // debug(cntr);
    if(cntr == 0){
        for(int i = n; i >= 1; --i)
            cout << i << " ";
        cout << endl;
        return;
    }
    vector<int> deg(n);
    int idx = -1, mx = 0;
    for(int i = 0; i < n; ++i){
        deg[i] = adj[i].size();
        if(deg[i] > mx){
            idx = i;
            mx = deg[i];
        }
    }
    vector<int> ans(n,0);
    iota(all(ans),1);
    sort(ans.begin(),ans.end(), [&](int a, int b){
        if(a < b) return str[a - 1][b - 1] == '1';
        return str[a - 1][b - 1] == '0';
    });
    rep(i, 0, n) cout << ans[i] << " ";
    cout << endl;
    // debug(adj);
}