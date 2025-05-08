/**
*    created: 2025-03-25 20:13:59
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
        int n,x;
        cin >> n >> x;
        vector<int> ar(n);
        for(int i = 0; i < n; ++i){
            cin >> ar[i];
        }
        sort(ar.rbegin(), ar.rend());
        int cntr = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            cntr++;
            if (cntr * ar[i] >= x) {
                ans++; cntr = 0;
            }
        }
        
        cout << ans << endl;
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}