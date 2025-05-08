/**
*    created: 2025-03-17 20:12:23
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
You are given an integer array 𝑎
 of size 𝑛
. Initially, all elements of the array are colored red.

You have to choose exactly 𝑘
 elements of the array and paint them blue. Then, while there is at least one red element, you have to select any red element with a blue neighbor and make it blue.

The cost of painting the array is defined as the sum of the first 𝑘
 chosen elements and the last painted element.

Your task is to calculate the maximum possible cost of painting for the given array.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1e18)));
        // we have to paint j elem and last elem is i
        // dp[i][j][0] = max cost of painting first i elements with j blue elements and last element is not blue
        // [1] means i have painted last element blue
        dp[0][0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                if (dp[i][j][1] != -1e18 && j < k) {
                    debug(i, j, dp[i][j][1]);
                    dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][1] + a[i]);
                }
                if (dp[i][j][0] != -1e18) {
                    if (j < k)
                        dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][0] + a[i]);
                    
                    dp[i+1][j][0] = max(dp[i+1][j][0], max(dp[i][j][0], a[i])); // left a[i]
                    dp[i+1][j][1] = max(dp[i+1][j][1], max(dp[i][j][0], a[i])); // took a[i]
                    debug(i, j, dp[i + 1][j][0], dp[i][j][0], dp[i + 1][j][1], dp[i][j][1]);
                }
            }
        }
        // debug(dp);
        int ans = 0;
        for (int j = 0; j <= k; j++) {
            ans = max(ans, dp[n][j][0]);
        }
        cout << ans << endl;


    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}