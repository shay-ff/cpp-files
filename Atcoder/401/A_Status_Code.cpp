/**
*    created: 2025-04-12 17:30:33
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
/*
You are given an integer 
S between 
100 and 
999 (inclusive).

If 
S is between 
200 and 
299 (inclusive), print Success; otherwise, print Failure.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;
        if(n >= 200 && n <= 299){
            cout << "Success" << endl;
        }else{
            cout << "Failure" << endl;
        }
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}