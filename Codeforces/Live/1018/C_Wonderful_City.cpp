/**
*    created: 2025-04-19 20:24:00
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
You are the proud leader of a city in Ancient Berland. There are 𝑛2
 buildings arranged in a grid of 𝑛
 rows and 𝑛
 columns. The height of the building in row 𝑖
 and column 𝑗
 is ℎ𝑖,𝑗
.

The city is beautiful if no two adjacent by side buildings have the same height. In other words, it must satisfy the following:

There does not exist a position (𝑖,𝑗)
 (1≤𝑖≤𝑛
, 1≤𝑗≤𝑛−1
) such that ℎ𝑖,𝑗=ℎ𝑖,𝑗+1
.
There does not exist a position (𝑖,𝑗)
 (1≤𝑖≤𝑛−1
, 1≤𝑗≤𝑛
) such that ℎ𝑖,𝑗=ℎ𝑖+1,𝑗
.
There are 𝑛
 workers at company A, and 𝑛
 workers at company B. Each worker can be hired at most once.

It costs 𝑎𝑖
 coins to hire worker 𝑖
 at company A. After hiring, worker 𝑖
 will:

Increase the heights of all buildings in row 𝑖
 by 1
. In other words, increase ℎ𝑖,1,ℎ𝑖,2,…,ℎ𝑖,𝑛
 by 1
.
It costs 𝑏𝑗
 coins to hire worker 𝑗
 at company B. After hiring, worker 𝑗
 will:

Increase the heights of all buildings in column 𝑗
 by 1
. In other words, increase ℎ1,𝑗,ℎ2,𝑗,…,ℎ𝑛,𝑗
 by 1
.
Find the minimum number of coins needed to make the city beautiful, or report that it is impossible.

*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n; cin >> n;
        vector<vector<int>> ar(n, vector<int>(n));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> ar[i][j];
            }
        }
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        int cost = 0;
        
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}