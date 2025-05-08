/**
*    created: 2025-04-09 20:12:40
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
You are given a binary string 
S
S of length 
N
N, i.e. 
S
i
=
0
S 
i
​
 =0 or 
1
1.

You can do the following operation as many times as you want (possibly zero):

Choose a prefix 
S
[
1
,
X
]
S[1,X] (
1
≤
X
≤
N
1≤X≤N) such that there are equal number of 
0
0s and 
1
1s in this prefix, and then flip
†
†
  that prefix.
For example, in the string 
001101
001101, we can choose the prefix of length 
4
4 which has 
2
2 
0
0s and 
2
2 
1
1s, flipping it produces 
110001
110001.

Count the number of possible strings you can obtain by doing these operations.

†
†
  To flip a prefix means to change all 
0
0s to 
1
1s and all 
1
1s to 
0
0s.


*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n; string s;
        cin >> n >> s;
        int ans = 0, cntr = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '0'){
                cntr++;
            }
            else{
                cntr--;
            }
            if(cntr == 0){
                ans++;
            }
        }
        cout << (ans == 0 ? 1 : (1LL << ans)) << endl;

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}