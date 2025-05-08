/**
*    created: 2025-03-19 20:53:55
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class U> using ordered_pset = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order(k) - returns an iterator to the k-th largest element (0-based)
// order_of_key(x) - returns the number of elements strictly smaller than x

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_multiset st;
        vector<int> answer(nums.size());
        for(int i = nums.size() - 1; i >= 0; --i){
            int count = st.order_of_key(nums[i]);
            answer[i] = count;
        }
        return answer;
    }
};
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n,m;
        cin >> n >> m;
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < m; ++i){
            int u,v,w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
        }
        int src, dest;
        cin >> src >> dest;
        vector<int> dist(n,1e18), parent(n, -1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();

            for(auto &x : adj[node]){
                auto [v, w] = x;
                if(dist[v] > dist[node] + w){
                    dist[v] = dist[node] + w;
                    pq.push({dist[v], v});
                    parent[v] = node;
                }
            }
        }
        if(dist[dest] == 1e18){
            show(-1);
            return;
        }
        vector<int> path;
        for(int i = dest; i != -1; i = parent[i]){
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        for(int i : path){
            cout << i << " ";
        }
        cout << endl;
        cout << dist[dest] << endl;
    };
    int T = 1;
    // cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}

