/**
*    created: 2025-04-08 14:21:47
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

template <class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
template <class T> using max_pq = priority_queue<T>;
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n, x;
        cin >> n >> x;
        vector<int> a(n), c(n);
        max_pq<int> pq;
        for(int i = 0; i < n; ++i){
            cin >> c[i];
        }
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        int curr = 0, tot = 0, ops = 0;
        for (int i = 0; i < n; ++i) {
            pq.push(c[i]);
            if(curr + x - tot < c[i]){
                curr += pq.top();
                pq.pop();
                ops++;
            }
            tot += c[i];
            x += a[i];
        }
        cout<< ops << endl;

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}