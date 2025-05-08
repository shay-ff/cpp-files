/**
*    created: 2025-04-24 20:11:11
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];

        int rem = -1;
        for(int i = 0; i < n; i++) {
            if(b[i] != -1) {
                rem = i;
                break;
            }
        }

        if(rem != -1) {
            int have = a[rem] + b[rem];
            for(int i = 0; i < n; i++) {
                if(b[i] != -1 && a[i] + b[i] != have) {
                    cout << 0 << "\n";
                    return;
                }
            }
            for(int i = 0; i < n; i++) {
                if(b[i] == -1) {
                    int pos = have - a[i];
                    if(pos < 0 || pos > k) {
                        cout << 0 << "\n";
                        return;
                    }
                }
            }
            cout << 1 << "\n";
            return;
        }

        int low = *max_element(a.begin(), a.end()), maxr = *min_element(a.begin(), a.end(), [&](int i, int j) {
            return (i + k) < (j + k);
        });
        maxr += k;

        int ans;
        if(maxr >= low) {
            ans = maxr - low + 1;
        } else {
            ans = 0;
        }
        show(ans);
    };

    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}