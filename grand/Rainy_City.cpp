#include <bits/stdc++.h>
using namespace std;
 
#define int long long

const int MAXD = 20;
 
int n, m;
vector<vector<int>> adj;
vector<int> depth, parent;
vector<vector<int>> lcaTable;
vector<int> diff;

void dfsLCA(int node, int par, int d) {
    depth[node] = d;
    parent[node] = par;
    for (int nxt : adj[node]) {
        if (nxt == par) continue;
        dfsLCA(nxt, node, d + 1);
    }
}
 
void buildLCA() {
    lcaTable.assign(n, vector<int>(MAXD, -1));
    for (int i = 0; i < n; i++) {
        lcaTable[i][0] = parent[i];
    }
    for (int j = 1; j < MAXD; j++) {
        for (int i = 0; i < n; i++) {
            if (lcaTable[i][j - 1] != -1)
                lcaTable[i][j] = lcaTable[lcaTable[i][j - 1]][j - 1];
        }
    }
}
 
int getLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diffDepth = depth[u] - depth[v];
    for (int i = 0; i < MAXD; i++) {
        if (diffDepth & (1 << i))
            u = lcaTable[u][i];
    }
    if (u == v) return u;
    for (int i = MAXD - 1; i >= 0; i--) {
        if (lcaTable[u][i] != lcaTable[v][i]) {
            u = lcaTable[u][i];
            v = lcaTable[v][i];
        }
    }
    return parent[u];
}
 
void dfsAccum(int node, int par) {
    for (int nxt : adj[node]) {
        if (nxt == par) continue;
        dfsAccum(nxt, node);
        diff[node] += diff[nxt];
    }
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    adj.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    depth.assign(n, 0);
    parent.assign(n, -1);
    dfsLCA(0, -1, 0);
    buildLCA();
    
    diff.assign(n, 0);
    
    for (int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        diff[u] += c;
        diff[v] += c;
        int l = getLCA(u, v);
        diff[l] -= c;
        if (parent[l] != -1)
            diff[parent[l]] -= c;
    }
    
    dfsAccum(0, -1);
    
    int ansCity = 0;
    int ansVal = diff[0];
    for (int i = 0; i < n; i++){
        if (diff[i] < ansVal) {
            ansVal = diff[i];
            ansCity = i;
        }
    }
    
    cout << ansCity + 1 << "\n";
    return 0;
}
