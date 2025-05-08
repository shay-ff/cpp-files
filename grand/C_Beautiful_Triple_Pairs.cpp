/**
*    created: 2025-03-13 03:57:24
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
Polycarp was given an array a of n integers. He really likes triples of numbers, so for each j (1≤j≤n−2) he wrote down a triple of elements [aj,aj+1,aj+2].

Polycarp considers a pair of triples b and c beautiful if they differ in exactly one position, that is, one of the following conditions is satisfied:

b1≠c1 and b2=c2 and b3=c3;
b1=c1 and b2≠c2 and b3=c3;
b1=c1 and b2=c2 and b3≠c3.

Find the number of beautiful pairs of triples among the written triples [aj,aj+1,aj+2].
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x : a)
            cin >> x;
        map<array<int, 3>, int> cnt;
        int ans = 0;
        for(int i = 0; i < n - 2; ++i){
            array<int, 3> cur = {a[i], a[i + 1], a[i + 2]};
            map<array<int, 3>, int> temp;
            temp[{0, cur[1], cur[2]}] = 1;
            temp[{cur[0], 0, cur[2]}] = 1;
            temp[{cur[0], cur[1], 0}] = 1;
            
            for(auto &trip : temp){
                ans += cnt[trip.first] - cnt[cur];
                cnt[trip.first] += 1;
            }
            cnt[cur] += 1;
        }
        cout << ans << endl;
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}