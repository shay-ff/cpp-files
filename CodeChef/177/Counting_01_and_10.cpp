/**
*    created: 2025-03-12 20:43:28
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
Given a binary string 
S
S, let 
X
X denote the number of 
01
01 subsequences and 
Y
Y denote the number of 
10
10 subsequences in it.

For example, for 
S
=
10010
S=10010, there are 
2
2 
01
01 subsequences and 
4
4 
10
10 subsequences, so 
X
=
2
X=2 and 
Y
=
4
Y=4.

Let 
f
(
S
)
=
(
X
,
Y
)
f(S)=(X,Y), i.e. the function value is the pair of values 
X
X and 
Y
Y for the given string.

Consider all binary strings of length 
N
N. How many distinct values of 
f
(
S
)
f(S) exist? It can be proven that the answer does not exceed 
1
0
18
10 
18
  in the given constraints.
*/

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;

        int ans = 0;
        for(int i = 0; i <= (n)/2; ++i){
            ans += i*(n-i) + 1;
        }
        cout << ans << '\n';

    };
    int T = 1;
    cin >> T;
   
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}