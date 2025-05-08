/**
*    created: 2025-04-08 20:07:21
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
        string s;
        cin >> s;
        int n = sz(s);
        int cntr = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '0'){
                cntr++;
            }
            else{
                ans = max(ans, cntr + 1); 
            }
        }
        show(n - ans);
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}