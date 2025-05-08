/**
*    created: 2025-04-19 20:30:43
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
using ll = long long;
const ll INF = (ll)4e18;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto solve_test = [&](int test_case) {
        int n;
        cin >> n;

        vector<vector<ll>> h(n, vector<ll>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> h[i][j];

        vector<ll> A(n), B(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        for(int j = 0; j < n; j++) cin >> B[j];

        // Build allowed tables for X (rows) and Y (cols)
        // allowX[i][v1][v2] forbids x_i=v1, x_{i+1}=v2 if false
        vector<array<array<bool, 2>, 2>> allowX(n - 1),
               allowY(n - 1);

        // initialize all to true
        for(int i = 0; i < n - 1; i++)
            for(int v1 = 0; v1 < 2; v1++)
                for(int v2 = 0; v2 < 2; v2++)
                    allowX[i][v1][v2] = allowY[i][v1][v2] = true;

        // Horizontal edges => constraints on Y
        for(int i = 0; i < n; i++) {
            for(int j = 0; j + 1 < n; j++) {
                ll d = h[i][j + 1] - h[i][j];
                if(abs(d) > 1) continue;
                // forbid exactly (y_j,y_{j+1}) with y_j - y_{j+1} == d
                for(int u1 = 0; u1 < 2; u1++) {
                    for(int u2 = 0; u2 < 2; u2++) {
                        if(u1 - u2 == d)
                            allowY[j][u1][u2] = false;
                    }
                }
            }
        }

        // Vertical edges => constraints on X
        for(int i = 0; i + 1 < n; i++) {
            for(int j = 0; j < n; j++) {
                ll d = h[i + 1][j] - h[i][j];
                if(abs(d) > 1) continue;
                for(int v1 = 0; v1 < 2; v1++) {
                    for(int v2 = 0; v2 < 2; v2++) {
                        if(v1 - v2 == d)
                            allowX[i][v1][v2] = false;
                    }
                }
            }
        }

        // Simple 2‑state DP for X
        vector<array<ll, 2>> dpX(n, {INF, INF}),
               dpY(n, {INF, INF});

        // Base cases
        dpX[0][0] = 0;
        dpX[0][1] = A[0];
        dpY[0][0] = 0;
        dpY[0][1] = B[0];

        // Fill dpX
        for(int i = 0; i + 1 < n; i++) {
            for(int v2 = 0; v2 < 2; v2++) {
                ll best = INF;
                for(int v1 = 0; v1 < 2; v1++) {
                    if(allowX[i][v1][v2])
                        best = min(best, dpX[i][v1]);
                }
                dpX[i + 1][v2] = best + (v2 ? A[i + 1] : 0);
            }
        }

        // Fill dpY
        for(int j = 0; j + 1 < n; j++) {
            for(int u2 = 0; u2 < 2; u2++) {
                ll best = INF;
                for(int u1 = 0; u1 < 2; u1++) {
                    if(allowY[j][u1][u2])
                        best = min(best, dpY[j][u1]);
                }
                dpY[j + 1][u2] = best + (u2 ? B[j + 1] : 0);
            }
        }

        // Get answers
        ll ansX = min(dpX[n - 1][0], dpX[n - 1][1]);
        ll ansY = min(dpY[n - 1][0], dpY[n - 1][1]);

        ll ans = (ansX < INF && ansY < INF ? ansX + ansY : -1LL);
        cout << ans << "\n";
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}