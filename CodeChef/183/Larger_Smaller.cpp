/**
*    created: 2025-04-23 20:04:02
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
You are given an array A of N positive integers.

An integer X is said to be good if there exists indices i and j (1 ≤ i, j ≤ N) such that 
Ai < X and X < Aj (i.e. there exists a smaller element and a larger element).

Find the number of good integers. It can be proven that the answer is always finite.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int lg = a[n - 1], sm = a[0];
        int ans = 0;
        ans = max(0LL, lg - sm - 1);
        show(ans);

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}