/**
*    created: 2025-03-08 20:56:26
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
#define yesno(x) cout << ((x) ? "Yes\n" : "No\n")
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

template <class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
template <class T> using max_pq = priority_queue<T>;
void pre_pro(){
}

void dxt(int test_case) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> ans(n, 0), temp(n, 0);
    vector<int> vis(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            queue<int> q;
            temp[i] = 0;
            q.push(i);
            vis[i] = 1;
            vector<int> comp;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                comp.push_back(u);
                for (auto [v, w] : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        temp[v] = temp[u] ^ w;
                        q.push(v);
                    } else {
                        if ((temp[u] ^ temp[v]) != w) {
                            cout << -1 << "\n";
                            return;
                        }
                    }
                }
            }
            int curr = 0;
            for (int b = 0; b < 61; ++b) {
                int cnt0 = 0, cnt1 = 0;
                for (auto x : comp) {
                    if (temp[x] & (1LL << b))
                        cnt1++;
                    else
                        cnt0++;
                }
                if (cnt0 < cnt1)
                    curr |= (1LL << b);
            }
            for (auto x : comp)
                ans[x] = curr ^ temp[x];
        }
    }
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";
}
