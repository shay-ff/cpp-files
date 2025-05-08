class Solution {
public:
    template <class T> struct BIT { //1-indexed
        int n; vector<T> t;
        BIT() {}
        BIT(int _n) {
            n = _n; t.assign(n + 1, 0);
        }
        T query(int i) {
            T ans = 0;
            for (; i >= 1; i -= (i & -i)) ans += t[i];
            return ans;
        }
        void upd(int i, T val) {
            if (i <= 0) return;
            for (; i <= n; i += (i & -i)) t[i] += val;
        }
        void upd(int l, int r, T val) {
            upd(l, val);
            upd(r + 1, -val);
        }
        T query(int l, int r) {
            return query(r) - query(l - 1);
        }
    };
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>> adj(n + 1);
        map<pair<int,int>, int> mp;
        for(int i = 0; i < n - 1; ++i){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            mp[{min(u,v), max(u,v)}] = w;
        }
        using ll = long long int;
        vector<ll> in(n + 1, 0), out(n + 1), parent(n + 1), dist(n + 1);
        int sec = 0;
        function<void(ll,ll)> dfs = [&](ll u, ll p){
            parent[u] = p;
            sec++;
            in[u] = sec;
            for(auto &[v,w] : adj[u]){
                if(v == p) continue;
                dist[v] = dist[u] + w;
                dfs(v,u);
            }
            out[u] = sec;
        };
        dfs(1,-1);
        BIT<int> bit(n + 1);
        vector<int> answer;
        for(ll i = 0; i < queries.size(); ++i){
            ll qt = queries[i][0];
            if(qt == 1){
                ll u = queries[i][1], v = queries[i][2], w = queries[i][3];
                ll prev = mp[{min(u, v), max(u, v)}];
                ll diff = w - prev;
                mp[{min(u, v), max(u, v)}] = w;
                if(parent[u] == v){
                    bit.upd(in[u], out[u], diff);
                } else
                    bit.upd(in[v], out[v], diff);
            } else{
                ll u = queries[i][1];
                ll ans = dist[u] + bit.query(in[u]);
                answer.push_back(ans);
            }
        }
        return answer;
    }
};©leetcode