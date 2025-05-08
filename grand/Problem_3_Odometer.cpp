/**
*    created: 2025-04-11 22:24:56
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())

int dp[20][2][2][20][20];

int solve(int n) {
    memset(dp, -1, sizeof(dp));
    string s = to_string(n);
    int szs = s.size();

    function<int(string&, int, bool, bool, int, vector<int>&)> find =
    [&](string &lim, int idx, bool tight, bool leading_zeroes, int len, vector<int> &freq) -> int {
        if(idx == szs) {
            if(len == 0) return 0; 
            int mx = *max_element(freq.begin(), freq.end());
            return (2 * mx >= len) ? 1 : 0;
        }
        
        int maxs = *max_element(freq.begin(), freq.end());
        int &ret = dp[idx][tight][leading_zeroes][len][maxs];
        if(ret != -1) return ret;
        
        int ans = 0;
        int ub = tight ? lim[idx] - '0' : 9;
        for(int d = 0; d <= ub; ++d) {
            bool newTight = tight && (d == ub);
            bool newLeadingZero = leading_zeroes && (d == 0);
            vector<int> newFreq = freq;
            int newLen = len;
            if(!newLeadingZero) {
                newFreq[d]++;
                newLen++;
            }
            ans += find(lim, idx + 1, newTight, newLeadingZero, newLen, newFreq);
        }
        
        return ret = ans;
    };

    vector<int> freq(10, 0);
    return find(s, 0, true, true, 0, freq);
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    freopen("odometer.in", "r", stdin);
    freopen("odometer.out", "w", stdout);

    int l, r;
    cin >> l >> r;

    int ans = solve(r) - solve(l - 1);
    show(ans);
    
    return 0;
}
