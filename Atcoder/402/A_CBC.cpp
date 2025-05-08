/**
*    created: 2025-04-19 17:30:17
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
You are given a string 
S consisting of uppercase and lowercase English letters. Print the string obtained by concatenating only the uppercase letters of 
S in their original order.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        string s;
        cin >> s;
        string ans = "";
        for(char c : s){
            if(isupper(c)){
                ans += c;
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