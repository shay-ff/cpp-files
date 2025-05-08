/**
*    created: 2025-03-13 05:52:48
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
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(auto &x : a)
            cin >> x;
        int mx = *max_element(a.begin(), a.end());
        vector<int> cnt(mx + 1, 0), mul(mx + 1, 0), ans(mx + 1, 0);
        for(auto x : a)
            cnt[x]++;
        for(int i = 1; i <= mx; ++i){
            for(int j = i; j <= mx; j += i){
                mul[i] += cnt[j];
            }
        }
        for(int i = 1; i <= mx; ++i){
            if(mul[i] < k) continue;
            for(int j = i; j <= mx; j += i){
                ans[j] = max(ans[j], i);
            }
        }
        for(auto &x : a)
            cout << ans[x] << endl;

    };
    int T = 1;
    // cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}