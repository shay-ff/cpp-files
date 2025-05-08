#include <bits/stdc++.h>
using namespace std;

const int maxm = 10000;


int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> stones(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i].first >> stones[i].second;
    }

    vector<int> fib = {1, 2};
    for(; fib.back() + fib[fib.size() - 2] <= maxm;){
        fib.push_back(fib.back() + fib[fib.size() - 2]);
    }
   
    set<int> s(fib.begin(), fib.end());

    map<int, int> dp;
    dp[0] = 0;  

    for (auto &ey : stones) { // yeh line
        int x = ey.first; // yeh line and next line
        int w = ey.second;
        map<int, int> ndp = dp; 
        
        for (auto &el : dp) { // yeh line
            int sum = el.first; // yeh line and next line
            int weight = el.second;
            int ns = sum + x;
            if (s.count(ns)) { 
                int newWeight = weight + w;
                ndp[ns] = max(ndp[ns], newWeight);
            }
        }

        dp = ndp;
    }

    int ans = 0;
    for (auto &el : dp) { // yeh line
        ans = max(ans, el.second); // yeh line
    }
    cout << ans << endl;
    return 0;
}