/**
*    created: 2025-03-14 00:37:19
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
const int INF = 1e18;
/*
You are given sequence a1, a2, ..., an of integer numbers of length n. Your task is to find such subsequence that its sum is odd and maximum among all such subsequences. It's guaranteed that given sequence contains subsequence with odd sum.

Subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

You should write a program which finds sum of the best subsequence.


*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n; cin >> n;
        vector<int> a(n);
        for(auto &x : a)
            cin >> x;
            

        int sum = 0;
        int mxp = INF, mnp = -INF;

        for (int x : a) {
            if (x > 0) sum += x;
            if (x % 2 != 0) {
                if (x > 0) mxp = min(mxp, x);
                else mnp = max(mnp, x);
            }
        }

        if (sum % 2 == 0) {
            sum -= min(abs(mnp), mxp);
        }

        show(sum);

    };
    int T = 1;
    // cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}