/**
*    created: 2025-03-12 20:00:45
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
        int A,B,C;
        cin >> A >> B >> C;
        if(A + B <= C || A + C <= B || B + C <= A){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }

    };
    int T = 1;
    // cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}