/**
*    created: 2025-04-23 20:24:17
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
template <class T> T Sqrt(T n) {
    T lo = 0, hi = n;
    while(lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        if(mid * mid <= n) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto solve_test = [&](int test_case) {
        int n, m;
        cin >> n >> m;
        int e = n * (n - 1) / 2;
        int graph_with0 = (n - 1) * (n - 2) / 2;
        int min_w = m > graph_with0 ? m - graph_with0 : 0;
        int d = 1 + 8 * (e-m);
        int f = sqrt(d);
        int s;
        if (f * f == d && (f + 1) % 2 == 0) {
            s = (f + 1) / 2;
        } else {
            s = (f + 1) / 2 + 1;
        }
        int max_w = n - s;
        int l = max_w - min_w + 1;
        int total = (min_w + max_w) * l / 2;
        show(total);
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}