/**
*    created: 2025-04-16 20:01:35
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
Beautiful Garden
Chef has a beautiful garden that contains 
N
N flowers. Initially, all the flowers are in full bloom. However, each flower is a bit shy – once plucked, the 
i
t
h
i 
th
​
  flower takes exactly 
T
i
T 
i
​
  days to regrow and bloom again.

Chef loves plucking flowers but also wants his garden to always look beautiful. For this reason, he insists that there are always at least 
K
K flowers blooming in the garden at any given time.

Over a period of 
D
D days (numbered from 
1
1 to 
D
D inclusive), Chef will pluck some of the blooming flowers. On any day, he can choose to pluck any number of blooming flowers as long as after plucking, there remain at least 
K
K blooming flowers.

Note that:

If 
i
t
h
i 
th
​
  flower is plucked on day 
X
X, it will regrow and be available again on day 
X
+
T
i
X+T 
i
​
 .
The same flower may be plucked multiple times, provided that it has regrown after a previous pluck.
Determine the maximum total number of times Chef can pluck a flower in 
D
D days while respecting the garden’s beauty requirement.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n,k,d;
        cin >> n >> k >> d;
        vector<int> t(n);
        for(int i = 0; i < n; ++i) cin >> t[i];
        set<int> st;
        for(int i = 0; i < n; ++i) st.insert(i);

        vector<vector<int>> temp(d + 1);
        int cans = 0;
        for(int day = 1; day <= d; ++day){
            for(auto x : temp[day]){
                st.insert(x);
            }
            if(sz(st) <= k) 
                continue;

            vector<int> tempflowers(st.begin(), st.end());
            sort(tempflowers.begin(), tempflowers.end(), [&](int a, int b){ 
                return t[a] < t[b]; 
            });

            int curr = sz(st) - k;
            for(int i = 0; i < curr; ++i){
                int f = tempflowers[i];
                st.erase(f);
                int regrow_day = day + t[f];
                if(regrow_day <= d){
                    temp[regrow_day].push_back(f);
                }
                cans++;
            }
        }
        cout << cans << endl;
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}