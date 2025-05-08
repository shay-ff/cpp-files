/**
*    created: 2025-04-12 17:31:12
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
One day, Takahashi performed 
N operations on a certain web site.

The 
i‑th operation 
(1≤i≤N) is represented by a string 
S 
i
​
 , which is one of the following:

S 
i
​
 = login: He performs a login operation and becomes logged in to the site.
S 
i
​
 = logout: He performs a logout operation and becomes not logged in to the site.
S 
i
​
 = public: He accesses a public page of the site.
S 
i
​
 = private: He accesses a private page of the site.
The site returns an authentication error if and only if he accesses a private page while he is not logged in.

Logging in again while already logged in, or logging out again while already logged out, does not cause an error. Even after an authentication error is returned, he continues performing the remaining operations.

Initially, he is not logged in.

Print the number of operations among the 
N operations at which he receives an authentication error.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;

        vector<string> s(n);
        for(int i = 0; i < n; ++i){
            cin >> s[i];
        }
        int ans = 0;
        bool can = false;
        for(int i = 0; i < n; ++i){
            if(s[i] == "login"){
                can = true;
            }else if(s[i] == "logout"){
                can = false;
            }else if(s[i] == "public"){
            }else if(s[i] == "private"){
                if(!can){
                    ans++;
                }
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