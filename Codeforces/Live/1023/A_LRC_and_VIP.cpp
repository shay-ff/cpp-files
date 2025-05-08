/**
*    created: 2025-05-05 20:05:34
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
You have an array 𝑎
 of size 𝑛
 — 𝑎1,𝑎2,…𝑎𝑛
.

You need to divide the 𝑛
 elements into 2
 sequences 𝐵
 and 𝐶
, satisfying the following conditions:

Each element belongs to exactly one sequence.
Both sequences 𝐵
 and 𝐶
 contain at least one element.
gcd
 (𝐵1,𝐵2,…,𝐵|𝐵|)≠gcd(𝐶1,𝐶2,…,𝐶|𝐶|)
 ∗
∗
gcd(𝑥,𝑦)
 denotes the greatest common divisor (GCD) of integers 𝑥
 and 𝑦
.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        int g = 0;
        for(int i = 0; i < n; ++i){
            g = __gcd(g, a[i]);
        }
        vector<int> ans(n, 2);
        bool ok = false;
        for(int i = 0; i < n; ++i){
            if(a[i] != g){
                ans[i] = 1;
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        for(int i = 0; i < n; ++i){
            cout << ans[i] << " ";
        }
        cout << endl;


    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}