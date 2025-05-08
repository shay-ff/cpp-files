/**
*    created: 2025-03-17 20:34:06
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
        int n,m;
        cin >> n >> m;
        vector<int> a(m);
        for(auto &x : a){
            cin >> x;
        }    
        vector<int> fromleft, fromright;
        for(int i = 0; i < m; ++i){
            int l = min(a[i], n - 1);
            int r = max(1ll, n - a[i]);
            fromleft.push_back(l);
            fromright.push_back(r);
        }
        vector<int> temp = fromright;
        sort(temp.begin(), temp.end());
        vector<int> pref(m + 1, 0);
        for(int i = 0; i < m; ++i){
            pref[i + 1] = pref[i] + temp[i];
        }
        int ways = 0;
        for(int i = 0; i < m; ++i){
            int idx = upper_bound(temp.begin(), temp.end(), fromleft[i]) - temp.begin();
            ways += (fromleft[i] + 1) * (idx) - pref[idx];
        }
        for(int i = 0; i < m; ++i){
            if(fromleft[i] >= fromright[i]){
                ways -= fromleft[i] - fromright[i] + 1;
            }
        }
        cout << ways << endl;
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}