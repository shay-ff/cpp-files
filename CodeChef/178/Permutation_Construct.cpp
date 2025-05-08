/**
*    created: 2025-03-19 20:00:37
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
A permutation of length 
N
N is an array of length 
N
N that contains every integer from 
1
1 to 
N
N exactly once.

Given 
N
N and 
K
K, find a permutation 
P
P of length 
N
N satisfying the following constraints:

P
i
≠
i
P 
i
​
 =i for all 
1
≤
i
≤
N
1≤i≤N
P
i
 
m
o
d
 
K
=
i
 
m
o
d
 
K
P 
i
​
 modK=imodK for all 
1
≤
i
≤
N
1≤i≤N
In case no such permutation exists, output 
−
1
−1 instead.
*/
template <typename T>
void randomizeAndPrint(vector<T>& arr) {
    // Seed the random number generator
    srand(time(NULL));
    
    // Perform Fisher–Yates shuffle (in-place randomization)
    for (int i = arr.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap arr[i] and arr[j]
        swap(arr[i], arr[j]);
    }
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n, k;
        cin >> n >> k;
        
        vector<int> pr(n + 1, 0);
        map<int,vector<int>> mp;
        for(int j = 1; j <= n; ++j){
            mp[j % k].push_back(j);
        }
        for(int p = 0; p < k; ++p){
            if(mp[p].size() == 1){
                cout << -1 << endl;
                return;
            }
            for(int j = 0; j < mp[p].size(); ++j){
                int a = mp[p][j];
                pr[a] = mp[p][(j + 1) % mp[p].size()];
            }
        }

        for(int i = 1; i <= n; ++i){
            cout << pr[i] << " ";
        }
        cout << endl;
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}