#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll kadane(const vector<ll>& a) {
    ll best = LLONG_MIN, cur = 0;
    for (ll x : a) {
        cur = max(x, cur + x);
        best = max(best, cur);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // 1) Check known-only runs
        bool bad = false;
        ll run = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                run += a[i];
                if (run > k) { bad = true; break; }
            } else {
                run = 0;
            }
        }
        if (bad) {
            cout << "No\n";
            continue;
        }

        // 2) Count zeros
        int zeroCount = count(s.begin(), s.end(), '0');
        if (zeroCount == 0) {
            // fully known
            if (kadane(a) == k) {
                cout << "Yes\n";
                for (ll x : a) cout << x << ' ';
                cout << '\n';
            } else {
                cout << "No\n";
            }
            continue;
        }

        // 3) compute safety margin M
        ll S = 0;
        for (int i = 0; i < n; i++) if (s[i] == '1') S += llabs(a[i]);
        ll M = S * (n + 1LL) + k + 1;

        // find zero runs
        vector<pair<int,int>> runs;
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                runs.emplace_back(i, j-1);
                i = j;
            } else {
                i++;
            }
        }

        int p = -1;
        // pick a zero position that is "safe"
        for (auto &pr : runs) {
            int L = pr.first, R = pr.second;
            int len = R - L + 1;
            if (len >= 2) {
                // interior to avoid known neighbors
                p = L + 1;
                break;
            } else {
                // single zero: ensure both neighbors (if exist) are non-positive
                int i0 = L;
                bool okL = (i0 == 0) || (s[i0-1] == '0' || a[i0-1] <= 0);
                bool okR = (i0 == n-1) || (s[i0+1] == '0' || a[i0+1] <= 0);
                if (okL && okR) {
                    p = i0;
                    break;
                }
            }
        }
        if (p == -1) {
            cout << "No\n";
            continue;
        }

        // 4) fill zeros
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i == p) a[i] = k;
                else a[i] = -M;
            }
        }

        cout << "Yes\n";
        for (ll x : a) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
