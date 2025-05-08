#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int int64_t
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define show(x) cout << x << endl
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353
// lb(x) : first greater or equal than x, ub(x) : first greater than x
template <class T> bool setmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template <class T> bool setmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void dxt(){
	int n, m;
    cin >> n >> m;
    vector<int> dp(n + 1, -INF);
    set<char> word = {'n', 'a', 'r', 'e', 'k'};
    string narek = "narek";

    dp[0] = 0;
    int curr = 0, nc = 0, sc = 0;
    /*i have to store number of (narek) till ith string,
	and the scoreC(~scoreP),  
	and what it changes after adding the (i + 1)th one,
	dp[i] = max(dp[i - 1], dp[i - 1] + currScore)*/
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        int tc = 0, tnc = 0, tcurr = curr;
        for (int j = 0; j < m; ++j) {
            if (word.count(s[j]))
                tc++;
            if (narek[tcurr] == s[j]) {
                tcurr++;
                if (tcurr == 5) {
                    tnc += 5;
                    tcurr = 0;
                }
            }
        }

        int tsc = tc - tnc;
        if (dp[i] + (tnc - tsc) > dp[i + 1]) {
            curr = tcurr;
            nc += tnc;
            sc += tsc;
            dp[i + 1] = dp[i] + (nc - sc);
        }
    }

    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << endl;
	// debug(dp);
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	startTime = clock();
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		// debug("--- Case #%d start ---", i);
		//printf("Case #%d: ", i);
		dxt();
		//cout << dxt() << endl;
		// debug("--- Case #%d end ---", i);
		// debug("time = %.5lf ", getCurrentTime());
		// debug("++++++++++++++++++++");

	}

	return 0;
}