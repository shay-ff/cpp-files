/**
*    created: 2025-04-03 20:24:09
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
A permutation of integers from 1
 to 𝑛
 is an array of size 𝑛
 where each integer from 1
 to 𝑛
 appears exactly once.

You are given a permutation 𝑝
 of integers from 1
 to 𝑛
. You have to process 𝑛
 queries. During the 𝑖
-th query, you replace 𝑝𝑑𝑖
 with 0
. Each element is replaced with 0
 exactly once. The changes made in the queries are saved, that is, after the 𝑖
-th query, all integers 𝑝𝑑1,𝑝𝑑2,…,𝑝𝑑𝑖
 are zeroes.

After each query, you have to find the minimum number of operations required to fix the array; in other words, to transform the current array into any permutation of integers from 1
 to 𝑛
 (possibly into the original permutation 𝑝
, possibly into some other permutation).

The operation you can perform to fix the array is the following one:

choose the integer 𝑖
 from 1
 to 𝑛
, replace the 𝑖
-th element of the array with 𝑖
.
Note that the answer for each query is calculated independently, meaning you do not actually apply any operations, just calculate the minimum number of operations.

*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
         int n;
    cin >> n;
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++){
        cin >> p[i];
    }
    // We'll decompose the permutation into cycles.
    // cycle_id[i] will hold the id of the cycle that index i belongs to.
    // cycle_len[id] will be the length of that cycle.
    vector<int> cycle_id(n+1, 0);
    vector<int> cycle_len; // 1-indexed id of cycle: cycle_len[cycleId-1] is its length.
    int cycleCount = 0;
    vector<bool> visited(n+1, false);
 
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cycleCount++;
            int cur = i;
            int len = 0;
            // traverse the cycle (even if the cycle is not “nice” we follow p as given)
            while (!visited[cur]){
                visited[cur] = true;
                cycle_id[cur] = cycleCount;
                len++;
                cur = p[cur];
            }
            cycle_len.push_back(len);
        }
    }
 
    // For the purpose of queries, note that initially the array is a permutation (so answer = 0).
    // We will mark a cycle as "broken" once at least one of its indices is replaced with 0.
    vector<bool> broken(cycleCount+1, false);  // cycle ids are 1-indexed
    long long ans = 0;
 
    // We have exactly n queries (each index is replaced exactly once).
    for (int q = 1; q <= n; q++){
        int d;
        cin >> d;
        // In the "current" array, position d is replaced with 0.
        // If the cycle containing d is not yet broken, then mark it broken and add its length.
        int cid = cycle_id[d];
        if (!broken[cid]){
            broken[cid] = true;
            ans += cycle_len[cid-1];
        }
        cout << ans << " ";
    }
    cout << endl;
        

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}