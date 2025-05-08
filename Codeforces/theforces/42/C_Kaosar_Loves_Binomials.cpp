/**
*    created: 2025-04-08 14:39:26
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
        int sum = 0, cntr = 0;
        for(int i = 1; i * i <= n; ++i){
            if(n % i == 0){
                sum += i;
                cntr++;
                if(i != n / i){
                    sum += n / i;
                    cntr++;
                }
            }
        }
        cout << sum - cntr << endl;
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}

