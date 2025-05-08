/**
*    created: 2025-03-25 20:28:32
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
        int n,m,k;
        cin >> n >> m >> k;

        int low = 1, high = 2e9, ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            int tg = ceil_div(m + 1, mid + 1);
            int total = (m - tg + 1) * n;
            if(total >= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        cout << ans << endl;
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}