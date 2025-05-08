/**
*    created: 2025-04-13 21:36:09
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
Saturnita's mood depends on an array 𝑎 of length 𝑛, which only he knows the meaning of, 
and a function 𝑓(𝑘,𝑎,𝑙,𝑟), which only he knows how to compute. Shown below is the 
pseudocode for his function 𝑓(𝑘,𝑎,𝑙,𝑟).

function f(k, a, l, r):
    ans := 0
    for i from l to r (inclusive):
        while k is divisible by a[i]:
            k := k / a[i]
        ans := ans + k
    return ans

You are given 𝑞 queries, each containing integers 𝑘, 𝑙, and 𝑟. For each query, 
please output 𝑓(𝑘,𝑎,𝑙,𝑟).
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n, q;
        cin >> n >> q;
        vector<int> ar(n);
        for(int i = 0; i < n; ++i){
            cin >> ar[i];
        }

        vector<vector<int>> prefix(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            int k = 1;
            for (int j = i; j < n; ++j) {
                while (k % ar[j] == 0) {
                    k /= ar[j];
                }
                prefix[i][j] = (j > 0 ? prefix[i][j - 1] : 0) + k;
            }
        }

        while (q--) {
            int k, l, r;
            cin >> k >> l >> r;
            l--; r--;
            int ans = 0;

            ans = prefix[l][r];
            cout << ans << endl;
        }
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}