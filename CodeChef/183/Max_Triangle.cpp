/**
*    created: 2025-04-23 20:01:00
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
You have N sticks of length 1, 2, ..., N respectively.

Can you make a non-degenerate triangle with some 3 sticks out of these N sticks? 
Find the maximum possible perimeter of a triangle you can make, or print -1 if not possible.

You can make a non-degenerate triangle with sticks of sizes A, B, and C if and only if 
2 * max(A, B, C) < A + B + C.

The perimeter of a triangle made with sticks of lengths A, B, and C is A + B + C.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;

        if(n < 4){
            show(-1);
            return;
        }
        else{
            if(2 * n - 1 < n + (n - 1) + (n - 2)){
                show(3 * n - 3);
            }
            else{
                show(-1);
            }
        }
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}