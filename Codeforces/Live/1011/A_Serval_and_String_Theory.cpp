/**
*    created: 2025-03-22 20:08:28
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string temp = s;
        reverse(temp.begin(), temp.end());
        if(s < temp){
            cout << "YES" << "\n";
            return;
        }
        if(k == 0){
            cout << "NO" << "\n";
            return;
        }
        for(int i = 1; i < n; ++i){
            if(s[i] != s[0]){
                cout << "YES" << "\n";
                return;
            }
        }
        cout << "NO" << "\n";
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}