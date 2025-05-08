/**
*    created: 2025-04-19 20:38:08
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
        vector<pair<int,int>> bulbs(n);
        int parityE = 0, parityO = 0;

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            bulbs[i] = {x, y};
            int p = (int)((x + y) & 1);
            if (p == 0)
                parityE ^= 1;
            else
                parityO ^= 1;
        }

        // Determine desired parity: if even-count is odd, want even; else want odd
        int want = (parityE == 1 ? 0 : 1);

        // Find and output any bulb with matching parity
        for (auto &b : bulbs) {
            int x = b.first, y = b.second;
            if (((x + y) & 1) == want) {
                cout << x << " " << y << '\n';
                break;
            }
        }
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}
/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<ll,ll>> bulbs(n);
        int parityE = 0, parityO = 0;

        for (int i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            bulbs[i] = {x, y};
            int p = (int)((x + y) & 1);
            if (p == 0)
                parityE ^= 1;
            else
                parityO ^= 1;
        }

        // Determine desired parity: if even-count is odd, want even; else want odd
        int want = (parityE == 1 ? 0 : 1);

        // Find and output any bulb with matching parity
        for (auto &b : bulbs) {
            ll x = b.first, y = b.second;
            if (((x + y) & 1) == want) {
                cout << x << " " << y << '\n';
                break;
            }
        }
    }

    return 0;
}

*/