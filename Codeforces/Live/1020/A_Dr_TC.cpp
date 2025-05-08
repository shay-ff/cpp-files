/**
*    created: 2025-04-24 20:05:16
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
        string s;
        cin >> s;
        int ans = 0;
        int count = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '1'){
                count++;
            }
        }
        ans = count * (n - 1) + (n - count) * 1;
        show(ans);
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}