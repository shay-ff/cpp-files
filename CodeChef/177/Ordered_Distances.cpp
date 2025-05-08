/**
*    created: 2025-03-12 20:07:47
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
Ordered Distances
Chef had a sequence of 
N
N distinct points 
X
1
,
X
2
,
.
.
.
,
X
N
X 
1
​
 ,X 
2
​
 ,...,X 
N
​
 .

Chef did the following action to get a new sequence of points 
Y
Y:

Choose a pivot index 
i
i (
1
≤
i
≤
N
1≤i≤N), and thus a pivot value 
P
=
X
i
P=X 
i
​
 .
Make a list 
L
L of the 
N
N pairs 
(
∣
X
j
−
P
∣
,
X
j
)
(∣X 
j
​
 −P∣,X 
j
​
 ) for each 
1
≤
j
≤
N
1≤j≤N, i.e. pair of (distance, value).
Sort the list 
L
L in increasing order
†
†
 .
Define 
Y
k
Y 
k
​
  as the second element in the 
k
k-th pair in this sorted list 
L
L.
For example,

Suppose we start with 
X
=
[
2
,
6
,
5
,
4
]
X=[2,6,5,4], pivot index 
i
=
3
i=3 and thus, 
P
=
X
3
=
5
P=X 
3
​
 =5.
List 
L
L = 
[
(
3
,
2
)
,
(
1
,
6
)
,
(
0
,
5
)
,
(
1
,
4
)
]
[(3,2),(1,6),(0,5),(1,4)]
Sorted order of List 
L
L = 
[
(
0
,
5
)
,
(
1
,
4
)
,
(
1
,
6
)
,
(
3
,
2
)
]
[(0,5),(1,4),(1,6),(3,2)]
Y
=
[
5
,
4
,
6
,
2
]
Y=[5,4,6,2] taking the second elements from the list.
Now, you are given the sequences 
X
X and 
Y
Y but you do not know the pivot index chosen by Chef. Can you recover any valid pivot index, or declare an inconsistency in the results. (i.e. no valid pivot index exists)

It is guaranteed the input values of the array 
X
X and 
Y
Y are all distinct, and that 
X
X is a permutation of 
Y
Y.

*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    auto solve_test = [&](int test_case){
        int N;
        cin >> N;
        vector<int> x(N), y(N);
        for (int i = 0; i < N; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> y[i];
        }
        
        int a = y[0];
        
        vector<pair<int, int>> temp;
        for (int t : x) {
            temp.push_back({abs(t - a), t});
        }
        sort(temp.begin(), temp.end());
        vector<int> curr;
        for (auto &p : temp) {
            curr.push_back(p.second);
        }
        
        if (curr != y) {
            cout << -1 << "\n";
            return;
        }
        
        int ans = -1;
        for (int i = 0; i < N; i++) {
            if (x[i] == a) {
                ans = i + 1;
                break;
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