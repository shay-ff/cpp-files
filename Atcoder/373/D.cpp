#include<bits/stdc++.h>
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
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 1e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353
/* "So do not lose heart nor fall into despair, for you will be superior if you are true in faith!" */
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




void dxt(int test_case) {
    int n, m;
    cin >> n >> m;

    vector<int> ans(n + 1, 1e18); 
    vector<vector<pair<int, int>>> graph(n + 1); 
    vector<bool> vis(n + 1, false); 

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, -w});
    }

    auto bfs = [&](int u) {
        queue<int> q;
        q.push(u);
        vis[u] = true;

        while (!q.empty()) {
            int t = q.front();
            q.pop();

            for (auto &e : graph[t]) {
                int v = e.first;
                int w = e.second;

                if (ans[v] == INF) {
                    ans[v] = ans[t] + w; 
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ans[i] = 0; 
            bfs(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

