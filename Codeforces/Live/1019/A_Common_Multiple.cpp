/**
*    created: 2025-04-21 20:05:45
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
        int z = 0;
        set<int> st;
        for(int i= 0; i < n; ++i){
            cin >> ar[i];
            if(ar[i] == 0) z++;
            else st.insert(ar[i]);
        }
        int ans = 0;
        if(z == n) show(z);
        else show(max((int)st.size(),z +1));

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}