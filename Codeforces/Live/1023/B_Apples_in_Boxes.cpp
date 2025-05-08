/**
*    created: 2025-05-05 20:08:28
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
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        map<int,int> cnt;
        int mn = INT_MAX, mx = -1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            cnt[a[i]]++;
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
            sum += a[i];
        }
        int span = mx - mn;
        bool tom;
        if(span >= k + 2) {
            tom = false;
        }
        else if(span - 1 == k && cnt[mx] >= 2) {
            tom = false;
        }
        else {
            tom = (sum % 2 == 1);
        }
        if (tom) {
            cout << "Tom" << endl;
        } else {
            cout << "Jerry" << endl;
        }

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}