/**
*    created: 2025-04-21 01:41:33
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
For the multiset of positive integers 𝑠={𝑠1,𝑠2,…,𝑠𝑘}, define the Greatest Common Divisor (GCD) and Least Common Multiple (LCM) of 𝑠 as follows:

gcd(𝑠) is the maximum positive integer 𝑥, such that all integers in 𝑠 are divisible by 𝑥.
lcm(𝑠) is the minimum positive integer 𝑥, that is divisible by all integers from 𝑠.

For example:
gcd({8,12})=4, gcd({12,18,6})=6, and lcm({4,6})=12.
Note that for any positive integer 𝑥, gcd({𝑥})=lcm({𝑥})=𝑥.

Orac has a sequence 𝑎 with length 𝑛. He came up with the multiset 𝑡={lcm({𝑎𝑖,𝑎𝑗}) | 𝑖<𝑗}, and asked you to find the value of gcd(𝑡) for him. In other words, you need to calculate the GCD of LCMs of all pairs of elements in the given sequence.
*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto solve_test = [&](int test_case) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int g = 0;
        map<int, int> freq;
        for(int i = 0; i < n; ++i) {
            freq[a[i]]++;
        }

        for(auto &[x, count] : freq) {
            for(auto &[y, count2] : freq) {
                if(x == y && count < 2) continue; 
                int lcm = (x / __gcd(x, y)) * y;
                g = __gcd(g, lcm);
                if(g == 1) {
                    cout << 1 << endl;
                    return;
                }
            }
        }
        cout << g << endl;
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}