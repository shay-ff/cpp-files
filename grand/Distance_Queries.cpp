/**
*    created: 2025-03-18 12:50:09
**/
#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void storeInorder(TreeNode* root, vector<int> &node){
        if(!root) return;
        storeInorder(root->left, node);
        node.push_back(root->val);
        storeInorder(root->right, node);
    }
    int lb(vector<int> &a, int key){
        int l = 0, r = a.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(a[m] < key){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if(l == a.size() || a[l] != key) return -1;
        return a[l];
    }
    int ub(vector<int> &a, int key){
        int l = 0, r = a.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(a[m] <= key){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if(l == a.size()) return -1;
        return a[l];
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nodes;
        storeInorder(root, nodes);
        vector<vector<int>> answer;
        for(auto &a : queries){
            int val1 = lb(nodes, a), val2 = ub(nodes,a);
            answer.push_back({val1, val2});
        }
        return answer;
    }
};
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n, q;
        cin >> n >> q;
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; ++i){
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> depth(n), parent(n);
        function<void(int, int, int)> dfsLCA = [&](int u, int par, int d){
            depth[u] = d;
            parent[u] = par;
            for(int v : adj[u]){
                if(v == par) continue;
                dfsLCA(v, u, d + 1);
            }
        };
        dfsLCA(0, -1, 0);
        vector<vector<int>> up(n, vector<int>(20));
        for(int i = 0; i < n; ++i){
            up[i][0] = parent[i];
        }
        for(int j = 1; j < 20; ++j){
            for(int i = 0; i < n; ++i){
                if(up[i][j - 1] != -1){
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
            }
        }
        function<int(int, int)> lca = [&](int u, int v){
            if(depth[u] < depth[v]) swap(u, v);
            for(int i = 19; i >= 0; --i){
                if(depth[u] - (1 << i) >= depth[v]){
                    u = up[u][i];
                }
            }
            if(u == v) return u;
            for(int i = 19; i >= 0; --i){
                if(up[u][i] != up[v][i]){
                    u = up[u][i];
                    v = up[v][i];
                }
            }
            return parent[u];
        };
        while(q--){
            int u, v;
            cin >> u >> v;
            --u, --v;
            int l = lca(u, v);
            int ans = depth[u] + depth[v] - 2 * depth[l] + 1;
            cout << ans - 1 << '\n';
        }

    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}