#include <bits/stdc++.h>
using namespace std;
const int maxm = 1'000'000;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> sto(n);
    for (int i = 0; i < n; i++) {
        cin >> sto[i].first >> sto[i].second;
    }
    
    int a = 1, b = 2;
    set<int> st;
    st.insert(a);
    st.insert(b);
    while(a + b <= maxm) {
        int c = a + b;
        a = b;
        b = c;
        st.insert(c);
    }
    map<pair<int,int>, int> dp;
    dp[{0, 0}] = 0;

    for (auto [x, w] : sto) {
        map<pair<int,int>, int> ndp = dp; 
        for (auto &el : dp) {
            int curr = el.first.first, g = el.first.second;
            int wgh = el.second;
            
            int sum = curr + x;
            if (sum > maxm) continue;
            
            int ngcd = (g == 0 ? x : __gcd(g, x));
            pair<int,int> nst = {sum, ngcd};
            ndp[nst] = max(ndp[nst], wgh + w);
        }
        dp = move(ndp);
    }
    int ans = -1;
    for (auto &br : dp) {
        int sum = br.first.first, g = br.first.second;
        int wigh = br.second;
        if (g == 1 && st.count(sum)) {
            ans = max(ans, wigh);
        }
    }
    cout << ans << "\n";
    return 0;
}
