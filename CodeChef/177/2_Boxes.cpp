/**
*    created: 2025-03-12 20:01:37
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
You have 
2
2 boxes, the first having 
X
X stones, and the second having 
Y
Y stones.

You want the (absolute) difference between the stones of the 
2
2 boxes to be exactly 
K
K.

Each second, you can take a stone from the 
1
s
t
1 
st
  box and put it in the 
2
n
d
2 
nd
 , or take from the 
2
n
d
2 
nd
  and put it in the 
1
s
t
1 
st
  box.

Find the minimum time till the difference between the stones of the 
2
2 boxes becomes exactly 
K
K. If it is impossible, print 
−
1
−1 instead.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first and only line of input contains 
3
3 integers - 
X
,
Y
X,Y and 
K
K.
Output Format
For each test case, output on a new line the minimum time to get the difference to exactly 
K
K or 
−
1
−1 if impossible.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int X, Y, K;
        cin >> X >> Y >> K;

        if ((X + Y) % 2 != K % 2) {
            cout << -1 << '\n';
            return;
        }
        
        int diff = abs(X - Y);
        
        if (diff == K) {
            cout << 0 << '\n';
        } else {
            cout << abs(diff - K) / 2 << '\n';
        }
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}