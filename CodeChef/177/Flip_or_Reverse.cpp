/**
*    created: 2025-03-12 20:18:55
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
A
A and want to convert it to another binary string 
B
B. Both have lengths 
N
N.

You can do either of the following operations at most 
⌈
N
2
⌉
⌈ 
2
N
​
 ⌉ times:

Type 
1
1: Choose 
(
L
,
R
)
(L,R) such that 
1
≤
L
≤
R
≤
N
1≤L≤R≤N, and flip 
A
i
A 
i
​
  for each 
L
≤
i
≤
R
L≤i≤R. To flip 
X
X means to replace it with 
1
−
X
1−X.

Type 
2
2: Choose 
(
L
,
R
)
(L,R) such that 
1
≤
L
≤
R
≤
N
1≤L≤R≤N, and reverse the subarray 
A
[
L
,
R
]
A[L,R]. Formally, simultaneously replace 
A
i
A 
i
​
  with 
A
L
+
R
−
i
A 
L+R−i
​
  for all 
L
≤
i
≤
R
L≤i≤R.

Find a sequence of operations of length at most 
⌈
N
2
⌉
⌈ 
2
N
​
 ⌉ to transform 
A
A to 
B
B. It can be proven that at least one valid sequence exists.


*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;
        string s, p;
        cin >> s >> p;
        vector<array<int, 3>> ans;
        
        for (int i = 0; i < n/2; i++) {
            int j = n - i - 1;
            if (s[i] == p[i] && s[j] == p[j])
                continue;
            
            if (s[i] != p[i] && s[j] != p[j]) {
                if (s[i] == p[j] && s[j] == p[i]) {
                    ans.push_back({2, i + 1, j + 1});
                    reverse(s.begin() + i, s.begin() + j + 1);
                } else {
                    ans.push_back({1, i + 1, j + 1});
                    for (int k = i; k <= j; k++){
                    s[k] = char('0' + '1' - s[k]);
                    }
                }
            }
            else if (s[i] != p[i]) { 
                ans.push_back({1, i + 1, i + 1});
                s[i] = char('0' + '1' - s[i]);
            }
            else {
                ans.push_back({1, j + 1, j + 1});
                s[j] = char('0' + '1' - s[j]);
            }
        }
        if (n % 2 == 1) {
            int m = n / 2;
            if (s[m] != p[m]) {
                ans.push_back({1, m + 1, m + 1});
                s[m] = char('0' + '1' - s[m]);
            }
        }
        cout << ans.size() << "\n";
        for (auto &op : ans) {
            cout << op[0] << " " << op[1] << " " << op[2] << "\n";
        }
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}