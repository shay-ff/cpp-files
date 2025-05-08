/**
*    created: 2025-04-19 20:14:54
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
You are the proud owner of many colorful gloves, and you keep them in a drawer. Each glove is in one of n
colors numbered 1 to n. Specifically, for each i from 1 to n, you have li
left gloves and ri right gloves with color i.

Unfortunately, it's late at night, so you can't see any of your gloves. In other words, you will only know the color and the type (left or right) of a glove after you take it out of the drawer.

A matching pair of gloves with color i consists of exactly one left glove and one right glove with color i.
Find the minimum number of gloves you need to take out of the drawer to guarantee that you have at least k
matching pairs of gloves with different colors.

Formally, find the smallest positive integer x such that:

For any set of x gloves you take out of the drawer, there will always be at least k matching pairs of gloves with different colors.
*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto solve_test = [&](int test_case) {
        int n, k;
        cin >> n >> k;
        vector<int> l(n), r(n);
        for(int i = 0; i < n; ++i) {
            cin >> l[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> r[i];
        }
        int mint = 0, maxt = 0;
        vector<int> takes(n);
        for(int i = 0; i < n; i++) {
            maxt += max(l[i], r[i]);
            takes[i] = min(l[i], r[i]);
        }
        sort(takes.rbegin(), takes.rend());
        for(int i = 0; i < k - 1 && i < n; i++) {
            mint += takes[i];
        }
        maxt += mint + 1;
        show(maxt);
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}