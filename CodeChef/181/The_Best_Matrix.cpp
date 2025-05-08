/**
*    created: 2025-04-09 20:17:11
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
A matrix 
A
A of size 
N
×
M
N×M is said to be best if and only if all of the following conditions are satisfied:

∣
A
[
x
1
]
[
y
1
]
−
A
[
x
2
]
[
y
2
]
∣
=
1
∣A[x 
1
​
 ][y 
1
​
 ]−A[x 
2
​
 ][y 
2
​
 ]∣=1 for all adjacent pair of cells 
(
x
1
,
y
1
)
(x 
1
​
 ,y 
1
​
 ) and 
(
x
2
,
y
2
)
(x 
2
​
 ,y 
2
​
 )

(
x
1
,
y
1
)
(x 
1
​
 ,y 
1
​
 ) and 
(
x
2
,
y
2
)
(x 
2
​
 ,y 
2
​
 ) are said to be adjacent if and only if 
∣
x
1
−
x
2
∣
+
∣
y
1
−
y
2
∣
=
1
∣x 
1
​
 −x 
2
​
 ∣+∣y 
1
​
 −y 
2
​
 ∣=1.
A
[
x
]
[
y
]
=
A
[
x
−
1
]
[
y
]
+
A
[
x
+
1
]
[
y
]
2
A[x][y]= 
2
A[x−1][y]+A[x+1][y]
​
  for all 
1
<
x
<
N
1<x<N and 
1
≤
y
≤
M
1≤y≤M.

A
[
x
]
[
y
]
=
A
[
x
]
[
y
−
1
]
+
A
[
x
]
[
y
+
1
]
2
A[x][y]= 
2
A[x][y−1]+A[x][y+1]
​
  for all 
1
≤
x
≤
N
1≤x≤N and 
1
<
y
<
M
1<y<M.

You are given a matrix 
A
A of size 
N
×
M
N×M, and want to make it a best matrix. Find the minimum number of values that need to be changed to obtain a best matrix.

*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        
        int ans = n * m; 
        for (int i : {-1,1}) {
            for (int j : {-1,1}) {
                map<int, int> mp; 
                for (int r = 0; r < n; ++r) {
                    for (int c = 0; c < m; ++c) {
                        int curr = a[r][c] - (r * i + c * j);
                        mp[curr]++;
                    }
                }
                int temp = 0;
                for (auto &[_, x] : mp) {
                    temp = max(temp, x);
                }
                ans = min(ans, n * m - temp);
            }
        }
        cout << ans << "\n";
    };

    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}