/**
*    created: 2025-03-15 17:33:57
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
You are given an integer sequence of length 
N: 
A=(A 
1
​
 ,A 
2
​
 ,…,A 
N
​
 ).

When splitting 
A at one position into two non-empty (contiguous) subarrays, find the maximum possible sum of the counts of distinct integers in those subarrays.

More formally, find the maximum sum of the following two values for an integer 
i such that 
1≤i≤N−1: the count of distinct integers in 
(A 
1
​
 ,A 
2
​
 ,…,A 
i
​
 ), and the count of distinct integers in 
(A 
i+1
​
 ,A 
i+2
​
 ,…,A 
N
​
 ).

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
        vector<int> pref(n), suff(n);
        map<int, int> cnt;
        for(int i = 0; i < n; ++i){
            cnt[a[i]]++;
            pref[i] = cnt.size();
        }
        cnt.clear();
        for(int i = n - 1; i >= 0; --i){
            cnt[a[i]]++;
            suff[i] = cnt.size();
        }
        int ans = 0;
        for(int i = 0; i < n - 1; ++i){
            ans = max(ans, pref[i] + suff[i + 1]);
        }
        cout << ans << endl;
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}