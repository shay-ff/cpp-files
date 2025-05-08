/**
*    created: 2025-03-25 20:17:06
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
        if(n == 1){
            cout << 1 << endl;
            return;
        }   
        if(n % 2 == 0){
            cout << -1 << endl;
        }
        else{
           for(int i = 1; i <=n; i += 2){
               cout << i << " ";
           }
           for(int i = 2; i < n; i += 2){
               cout << i << " ";
           }
            cout << endl;
        }

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}