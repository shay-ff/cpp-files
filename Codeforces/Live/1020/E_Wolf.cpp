/**
*    created: 2025-04-24 20:43:32
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
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        string s;
        cin >> n >> s;
        s = "$" + s;  

        vector<int> u_id(n + 2, -1), d_id(n + 2, -1), c_id(n + 2, -1);
        int nextId = 0;

       
        for(int i = 1; i <= n; i++) {
            if(s[i] == '0') {
                u_id[i] = nextId++;
                d_id[i] = nextId++;
            } else {
                c_id[i] = nextId++;
            }
        }

        dsu uf(nextId);
        vector<int> weight(nextId, 0);

        for(int j = 1; j <= n; j++) {
            if(s[j] == '0') {
                weight[u_id[j]] = j - 1;
                weight[d_id[j]] = (int)n - j;
            } else {
                weight[c_id[j]] = 1;
            }
        }

        for(int j = 1; j < n; j++) {
            if(s[j] == '0' && s[j + 1] == '0') {
                uf.merge(u_id[j], u_id[j + 1]);
                uf.merge(d_id[j], d_id[j + 1]);
            }
        }
        for(int i = 1; i <= n; i++) {
            if(s[i] == '1') {
                if(i > 1 && s[i - 1] == '0')
                    uf.merge(c_id[i], d_id[i - 1]);
                if(i < n && s[i + 1] == '0')
                    uf.merge(c_id[i], u_id[i + 1]);
            }
        }

        vector<int> compSum(nextId, 0);
        int ans = 0;
        for(int id = 0; id < nextId; id++) {
            int root = uf.leader(id);
            compSum[root] += weight[id];
            ans = max(ans, compSum[root]);
        }

        cout << ans << '\n';
    };
    int T = 1;
    cin >> T;   
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}