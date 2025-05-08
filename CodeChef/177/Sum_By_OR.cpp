/**
*    created: 2025-03-12 21:19:44
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

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;
        vector<int> ar(n);

        for (int i = 0; i < n; i++){
            cin >> ar[i];

        }
        int mx = *max_element(ar.begin(), ar.end());
        int bits = 0;
        while((1LL << bits) <= mx) bits++;
        if(bits == 0) bits = 1;
        int size = 1LL << bits;
        vector<int> F(size, 0), dp(size, 0);
        for(int i = 0; i < n; i++){
            F[ar[i]]++;
        }
        for (int mask = 0; mask < size; mask++){
            dp[mask] = F[mask];
        }

        for (int i = 0; i < bits; i++){
            for (int mask = 0; mask < size; mask++){
                if(mask & (1LL << i))
                    dp[mask] += dp[mask ^ (1LL << i)];
            }
        }

        int torev = 0, mxbits = size - 1;
        for (int mask = 0; mask < size; mask++){
            torev += F[mask] * dp[mxbits ^ mask];
        }
        torev /= 2;
        cout << n * (n - 1) - torev << "\n";

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}