/**
*    created: 2025-04-13 21:05:51
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
        int n; cin >> n;
        vector<int> ar(n), pref(32, 0);
        for(int i = 0; i < n; ++i){
            cin >> ar[i];
            for(int j = 0; j < 32; ++j){
                if(ar[i] & (1 << j)){
                    pref[j]++;
                }
            }
        }
        
        int sum = 0;
        for(int i = 0; i < n; ++i){
            int ans = 0;
            for(int j = 0; j < 32; ++j){
                if(ar[i] & (1 << j)){
                    ans += (int)(n - pref[j]) * (1LL << j);
                } else {
                    ans += (int)pref[j] * (1LL << j);
                }
            }
            sum = max(sum, ans);
        }
        cout << sum << endl;
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}