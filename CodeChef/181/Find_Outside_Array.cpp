/**
*    created: 2025-04-09 20:01:50
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
        vector<int> a(n);
        map<int,int> mp;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            mp[a[i]] = i;
        }
        sort(a.begin(),a.end());
        if(a[0] < 0){
            cout << a[0] << " " << a[0] << endl;
        }
        else if(a.back() > 0){
            cout << a.back() << " " << a.back() << endl;
        }
        else if(a[0] == a.back() && a[0] == 0){
            cout << -1 << endl;
        }
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}