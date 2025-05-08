#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007;

void dxt(int test_case) {
    int n, q;
    cin >> n;

    vector<int> a(n), diff(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        diff[i - 1] = abs(a[i] - a[i - 1]);
    }

    int t = n - 1;
    int d = 25;
    vector<vector<int>> st(d, vector<int>(t));

    for (int i = 0; i < t; ++i) {
        st[0][i] = diff[i];
    }
    for (int i = 1; (1LL << i) <= t; ++i) {
        for (int j = 0; j + (1LL << i) <= t; ++j) {
            st[i][j] = __gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    for(int i = 0; i < 5; ++i){
    	for(int j = 0; j < t; ++j){
    		cout << st[i][j] << " ";
    	}
    	cout << endl;
    }
    auto query = [&](int l, int r) {
        if (l > r) return 0LL;
        int j = (int)log2(r - l + 1);
        return __gcd(st[j][l], st[j][r - (1 << j) + 1]);
    };

    // while (q--) {
    //     int l, r;
    //     cin >> l >> r;
    //     --l, --r;
    //     cout << ((l == r) ? 0 : query(l, r - 1)) << " ";
    // }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        dxt(i);
    }
    return 0;
}
/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 
*/
