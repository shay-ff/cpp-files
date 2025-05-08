/**
*    created: 2025-04-21 21:18:42
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto solve_test = [&](int test_case) {
        int n;
        cin >> n;
        vector<int> a(n);
        int max_a = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] > max_a) max_a = a[i];
        }
        int max_depth = max_a + 1;
        vector<int> d(n);
        for(int i = 0; i < n; i++) {
            if(a[i] == -1) d[i] = max_depth;
            else d[i] = a[i];
        }

        // Build Cartesian tree: max-heap on d[], in-order by index
        vector<int> left(n, -1), right(n, -1), parent(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            int last = -1;
            while(!st.empty() && d[st.top()] < d[i]) {
                last = st.top();
                st.pop();
            }
            if(!st.empty()) {
                // i becomes the right child of st.top()
                right[st.top()] = i;
                parent[i] = st.top();
            }
            if(last != -1) {
                // last becomes left child of i
                left[i] = last;
                parent[last] = i;
            }
            st.push(i);
        }
        int root = -1;
        for(int i = 0; i < n; i++) {
            if(parent[i] == -1) {
                root = i;
                break;
            }
        }

        // Assign permutation values by DFS: larger depths get larger values
        vector<int> p(n);
        int cur = n;
        function<void(int)> dfs = [&](int u) {
            if(u == -1) return;
            // assign this node the next largest remaining value
            p[u] = cur--;
            // recurse on left and right
            dfs(left[u]);
            dfs(right[u]);
        };
        dfs(root);

        // Output the permutation
        for(int i = 0; i < n; i++) {
            cout << p[i] << (i + 1 < n ? ' ' : '\n');
        }
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}