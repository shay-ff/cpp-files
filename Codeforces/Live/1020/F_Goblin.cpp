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
        if(x == y) return x;
        if(-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
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
        if(parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for(int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for(int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for(int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
        [&](const std::vector<int>& v) {
            return v.empty();
        }),
        result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto solve_test = [&](int test_case) {
        int n;
        string s;
        cin >> n >> s;
        s = "$" + s;

        vector<int> row_wise(n + 5), diag(n + 5), cols(n + 5);
        int cntr = 0;

        for(int i = 1; i <= n; i++) {
            if(s[i] == '0') {
                diag[i] = cntr++;
                row_wise[i] = cntr++;
            } else {
                cols[i] = cntr++;
            }
        }

        dsu ds(2 * cntr);
        vector<int> adj(cntr), len(cntr);
        for(int i = 1; i <= n; i++) {
            if(s[i] == '0') {
                adj[diag[i]] = n - i;
                adj[row_wise[i]] = i - 1;
            } else {
                adj[cols[i]] = 1;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(s[i] == '1') {
                if(i < n && s[i + 1] == '0') {
                    ds.merge(cols[i], row_wise[i + 1]);
                }
                if(i > 1 && s[i - 1] == '0') {
                    ds.merge(cols[i], diag[i - 1]);
                }
            }
        }
        for(int i = 1; i < n; i++) {
            if(s[i] == '0' && s[i + 1] == '0') {
                ds.merge(row_wise[i], row_wise[i + 1]);
                ds.merge(diag[i], diag[i + 1]);
            }
        }

        int ans = 0;
        for(int i = 0; i < cntr; i++) {
            int par = ds.leader(i);
            len[par] += adj[i];
            ans = max(ans, len[par]);
        }
        show(ans);
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}
// 100
// 010
// 001


// 0011001
// 1111001
// 1001001
// 1010001
// 1011101
// 1011011
// 1011000

/*
1
105
0101001100110100111001111011000110101010100110101011001011101101010010100010110110101110011101101001100111
*/