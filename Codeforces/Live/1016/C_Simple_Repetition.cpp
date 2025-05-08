/**
*    created: 2025-04-08 20:13:14
**/
#include <bits/stdc++.h>
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

int modpow(int a, int b, int mod) {
    int result = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1)
            result = (__int128)result * a % mod;
        a = (__int128)a * a % mod;
        b >>= 1;
    }
    return result;
}

bool check_composite(int n, int d, int a) {
    int x = modpow(a, d, n);
    if(x == 1 || x == n - 1)
        return false;
    int d_copy = d;
    while(d_copy != n - 1) {
        x = (__int128)x * x % n;
        d_copy *= 2;
        if(x == n - 1)
            return false;
        if(x == 1)
            return true;
    }
    return true;
}

bool miller_rabin(int n, const vector<int>& bases = {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
    if(n < 2) return false;
    if(n <= 3) return true;
    if(n % 2 == 0) return false;
    int d = n - 1;
    while(d % 2 == 0)
        d /= 2;
    for (int a : bases) {
        if(a > n - 2) break;
        if(check_composite(n, d, a))
            return false;
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    auto solve_test = [&](int test_case) {
        int n, k;
        cin >> n >> k;
        if(k == 1) {
            cout << (miller_rabin(n) ? "YES\n" : "NO\n");
            return;
        }
        else{
            if(n != 1) {
                cout << "NO\n";
                return;
            }
            if(!miller_rabin(k)) {
                cout << "NO\n";
                return;
            }
            int rep = 0, INF = LLONG_MAX;
            for (int i = 0; i < k; i++) {
                if(rep > (INF - 1) / 10) {
                    cout << "YES\n";
                    return;
                }
                rep = rep * 10 + 1;
            }
            cout << (miller_rabin(rep) ? "YES\n" : "NO\n");
        }
    };
    
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
    return 0;
}
