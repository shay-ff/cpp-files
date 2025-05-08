#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
using ll = long long;
const int mod = 1000000007;
const char nl = '\n';

#ifdef ONLINE_JUDGE
#define debug(x...)
#else
#include "debug.cpp"
#endif

void hello() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));

    ll tot = (n - k + 1)/2;
    ll ans = max(0LL, a[n - tot] - a[tot - 1] + 1);
    cout << ans << nl;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll test;
    cin >> test;
    while (test--) {
        hello();
    }
    return 0;
}