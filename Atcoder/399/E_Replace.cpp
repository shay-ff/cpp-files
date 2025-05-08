/**
*    created: 2025-03-29 17:43:00
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
You are given a positive integer 
N and two strings 
S and 
T, each of length 
N and consisting of lowercase English letters.

Determine whether it is possible to make 
S identical to 
T by repeating the operation below any number of times (possibly zero). If it is possible, also find the minimum number of operations required.

Choose two lowercase English letters 
x,y and replace every occurrence of 
x in 
S with 
y.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        string s,t;
        cin >> n >> s >> t;
        
        vector<int> cnt(26, -1);
        for(int i = 0; i < n; ++i){
            if(cnt[s[i] - 'a'] == -1){
                cnt[s[i] - 'a'] = t[i] - 'a';
            }else if(cnt[s[i] - 'a'] != (t[i] - 'a')){
                cout << -1 << endl;
                return;
            }
        }
        // we have to check that the mapping is bijective : which just mean whether its bipartite graph or not
        int cntr = 0;
        for(int i = 0; i < 26; ++i){
            if(cnt[i] != -1 && cnt[i] != i){
                cntr++;
            }
        }
        vector<int> vis(26, 0);
        int cyc = 0;
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            int v = cnt[u];
            if(v != -1 && v != u){
                if(vis[v] == 0) {
                    dfs(v);
                } else if(vis[v] == 1) {
                    cyc++;
                }
            }
            vis[u] = 2;
        };

        for(int i = 0; i < 26; ++i){
            if(cnt[i] != -1 && !vis[i] && i != cnt[i]){
                dfs(i);
            }
        }
        set<char> opt;
        for (int i = 0; i < 26; i++){
            if(cnt[i] != -1 && cnt[i] != i)
                opt.insert(t[i]);
        }
        int left = 26 - opt.size();
        if(left == 0 && cntr > 0){
            cout << "-1\n";
            return;
        }
        cout << cntr + cyc << endl;
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}