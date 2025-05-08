/**
*    created: 2025-04-24 21:40:34
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case) {
        int n;
        cin >> n;
        for(int i = 1; i < n; ++i) {
            int x, y;
            cin >> x >> y;
        }

        auto query1 = [&](const vector<int>& nodes) {
            cout << "? 1 " << sz(nodes) << " ";
            for (auto &x : nodes) cout << x << " ";
            cout << endl;
            cout.flush();
            int sum;
            cin >> sum;
            return sum;
        };

        auto query2 = [&](int u) {
            cout << "? 2 " << u << endl;
            cout.flush();
        };

        int r;
        int r1 = query1({1});
        if (abs(r1) == 1) {
            r = 1;
        } else {
            int low = 2, high = n;
            while (low < high) {
                int mid = (low + high) / 2;
                vector<int> sub_nodes;
                for (int i = 2; i <= mid; ++i) {
                    sub_nodes.push_back(i);
                }

                int sum1 = query1(sub_nodes);  
                query2(1);                     
                int total = query1({});      
                vector<int> full;
                for (int i = 2; i <= n; ++i) full.push_back(i);
                int sum2 = query1(full);      
                query2(2);                     
                if (sum2 - sum1 == 2 * sub_nodes.size()) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            r = low;
        }

        query2(r);
        vector<int> dist(n + 1);
        for (int i = 1; i <= n; ++i) {
            dist[i] = query1({i});
        }

        vector<int> ans(n + 1);
        ans[r] = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == r) continue;
            ans[i] = dist[i];
        }

        cout << "! ";
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout.flush();
    };

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve_test(i);
    }
}

// 1 is centre, so the graph is a star
// if 1 is root then f(u) is just distance from 1 to u else say v is root then
// f(u) = distance from 1 to v + distance from 1 to u
// then if f(u) == 1 means u is the root
// else i have to find the root, how?
// what if i do a binary search on the nodes, like to find the root
// i can do a query on the nodes and see if the sum is equal to the number of nodes
// if it is then the root is in the first half, else in the second
