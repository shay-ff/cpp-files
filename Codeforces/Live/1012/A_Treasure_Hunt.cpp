/**
*    created: 2025-03-23 17:04:31
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

template <class T> T floor_div(T x, T y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x >= 0) return x / y;
    return (x + 1) / y - 1;
}

template <class T> T ceil_div(T x, T y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x <= 0) return x / y;
    return (x - 1) / y + 1;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int x,y,t;
        cin >> x >> y >> t;
        int ans = 0;
        if(t % (x + y) < x){
            ans = t / (x + y) * 2;
            if(t % (x + y) >= x){
                ans++;
            }
        }else{
            ans = t / (x + y) * 2 + 1;
        }
        cout << ((ans & 1) ? "Yes" : "No") << endl;
    };
    int T = 1;
    cin >> T;       
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}