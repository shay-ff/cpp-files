/**
*    created: 2025-03-17 20:05:37
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
You are given two integers n and k; k is an odd number not less than 3. Your task is to turn n into 0.

To do this, you can perform the following operation any number of times: choose a number x from 1 to k and subtract it from n. However, if the current value of n is even (divisible by 2), then x must also be even, and if the current value of n is odd (not divisible by 2), then x must be odd.

In different operations, you can choose the same values of x, but you don't have to. So, there are no limitations on using the same value of x.

Calculate the minimum number of operations required to turn n into 0.
*/
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
        int n,k;
        cin >> n >> k;
        if(n%2 == 0){
            cout << (n + k - 2) / (k - 1) << endl;
        }
        else{
            cout << 1 + ((n - k) + (k - 2)) / (k - 1) << endl;
        }
        
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}