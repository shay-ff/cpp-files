/**
*    created: 2025-04-13 21:13:27
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

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n,m,k;
        cin >> n >> m >> k;
        if(n % k == 0 || m % k == 0){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    cout << ((i + j) % k) + 1 << " ";
                }
                cout << endl;
            }
        } 
        else{
            map<int,int> mp;
            int div = 0;
            for(int i = 1; i < k; ++i){
                if((k % i != 0) && __gcd(i, k) == 1){
                    div = i;
                    break;
                }
            }
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    mp[((i * m + j) * div) % k + 1]++;
                    cout << ((i * m + j) * div) % k + 1 << " ";
                }
                cout << endl;
            }
            set<int> st;
            for(auto it : mp){
                st.insert(it.second);
            }
            assert(st.size() == 1);
        }
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}
// 3 4 2
// 1 2 1 2
// 2 1 2 1
// 1 2 1 2

// 1 2 1
// 2 1 2
// 1 2 1