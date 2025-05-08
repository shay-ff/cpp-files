/**
*    created: 2025-04-09 20:56:37
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
        vector<int> p(n + 1);
        for(int i = 2; i <= n; ++i){
            cin >> p[i];
        }
        if(n & 1){
            cout << -1 << '\n';
            return;
        }
        bool feas = true;
        for(int i = 2; i <= n; ++i){
            if(p[i] != p[2] && i != p[2]){
                feas = false;
                break;
            }
        }
        if(!feas){
            cout << -1 << '\n';
            return;
        }
        vector<int> have, ans(n + 1, 0);
        for(int i = 1; i <= n; ++i){
            if(i != p[2]){
                have.push_back(i);
            }
        }
        int curr = 1;
        if(!have.empty()){
            int leaf = have.back();
            have.pop_back();
            ans[p[2]] = curr;
            ans[leaf] = curr;
            curr++;
        }
        while(sz(have) >= 2){
            int u = have.back();
            have.pop_back();
            int v = have.back();
            have.pop_back();
            ans[u] = curr;
            ans[v] = curr;
            curr++;
        }
        for(int i = 1; i <= n; ++i){
            cout << ans[i] << ' ';
        }
        cout << endl;


    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}