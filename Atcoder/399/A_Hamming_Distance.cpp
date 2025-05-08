/**
*    created: 2025-03-29 17:30:20
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
You are given a positive integer 
N and two strings 
S and 
T, each of length 
N and consisting of lowercase English letters.

Find the Hamming distance between 
S and 
T. That is, find the number of integers 
i such that 
1≤i≤N and the 
i-th character of 
S is different from the 
i-th character of 
T.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int ans = 0;
        for(int i = 0; i < sz(s); ++i){
            if(s[i] != t[i]){
                ans++;
            }
        }
        cout << ans << endl;
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}