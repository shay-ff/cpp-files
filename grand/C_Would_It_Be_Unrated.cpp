/**
*    created: 2025-04-01 20:11:10
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

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        string s;
        // take input of full line
        getline(cin, s);
        set<char> st;
        for(auto& b : s){
            if(isalpha(b)){
                b = tolower(b);
                st.insert(b);
            }
        }
        for(auto &b : st){
            if(alpha[b-'a'] != '&'){
                alpha[b-'a'] = '&';
            }
        }
        debug(alpha);
        cout << st.size() << endl;
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}