/**
*    created: 2025-04-09 20:00:24
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
Move Grid
You are located at the coordinate 
(
0
,
0
)
(0,0) on a 
2
2D grid with perpendicular 
X
X and 
Y
Y axes.

You will do the following moves:

first, 
A
A units along positive 
X
X axis
then, 
B
B units along positive 
Y
Y axis
then, 
C
C units along negative 
X
X axis
finally, 
D
D units along negative 
Y
Y axis
Find the coordinates of your final position.

Input Format
The first and only line of input contains 
4
4 integers - 
A
,
B
,
C
A,B,C and 
D
D.
Output Format
For each test case, output on a new line the 
X
X and 
Y
Y coordinates of your final position.

Constraints
1
≤
A
,
B
,
C
,
D
≤
10
1≤A,B,C,D≤10
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        int x = A - C;
        int y = B - D;
        cout << x << " " << y << endl;
        
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}