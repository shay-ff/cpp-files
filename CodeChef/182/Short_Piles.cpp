/**
*    created: 2025-04-16 21:10:01
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
        int x,y,z;
        cin >> x >> y >> z;

        int tot = x + 2 * y + 3 * z;
        if((x + y + z) >= 2 || ((x > 0 && (y == 0 && z == 0)) || (y > 0 && (x == 0 && z == 0)) && (z > 0 && (y == 0 && x == 0)))) show("Alice");
        else show("Bob");
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}