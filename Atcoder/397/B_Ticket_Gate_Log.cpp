/**
*    created: 2025-03-15 17:32:07
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
Takahashi aggregated usage records from ticket gates. However, he accidentally erased some records of entering and exiting stations. He is trying to restore the erased records.

You are given a string 
S consisting of i and o. We want to insert zero or more characters at arbitrary positions in 
S so that the resulting string satisfies the following conditions:

Its length is even, and every odd-numbered (1st, 3rd, ...) character is i while every even-numbered (2nd, 4th, ...) character is o.
Find the minimum number of characters that need to be inserted. It can be proved under the constraints of this problem that by inserting an appropriate finite number of characters, 
S can be made to satisfy the conditions.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        string s;
        cin >> s;
        int cnt = 0;
        char ex = 'i';
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ex) {
                ex = (ex == 'i' ? 'o' : 'i');
            } else {
                cnt++;
                ex = (ex == 'i' ? 'o' : 'i');
                ex = (ex == 'i' ? 'o' : 'i');
            }
        }
        if ((s.size() + cnt) % 2 == 1)
            cnt++;
        cout << cnt << "\n";
    };;
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}