/**
*    created: 2025-03-25 20:06:11
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
        string temp = "01032025";
        map<int, int> mp;
        for(auto x: temp){
            mp[x-'0']++;
        }
        vector<int> ar(n);
        for(int i = 0; i < n; ++i){
            cin >> ar[i];
        }
        int idx = -1;
        for(int i = 0; i < n; ++i){
            if(mp.find(ar[i]) != mp.end()){
                mp[ar[i]]--;
                if(mp[ar[i]] == 0){
                    mp.erase(ar[i]);
                }
            }
            if(mp.empty()){
                idx = i + 1;
                break;
            }
        }
        cout << ((idx == -1) ? 0 : idx) << endl;

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}