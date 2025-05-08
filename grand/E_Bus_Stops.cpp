#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
#define int long long
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const int N = 1e6;
  vector<int> dp(N + 1), freq(N + 1);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    freq[x]++;
  }
  int ans = 0;
  for (int i = N; i >= 1; i--) {
    if (freq[i]){
        int cnt = 0;
        for (int j = 2 * i; j <= N; j += i) {
            cnt += freq[j];
            dp[i] -= dp[j];
        }
        dp[i] += cnt * (cnt - 1) / 2 + cnt;
        continue; 
    }
    int cnt = 0;
    for (int j = 2 * i; j <= N; j += i) {
      cnt += freq[j];
      dp[i] -= dp[j];
    }
    if(cnt)
    dp[i] += cnt * (cnt - 1) / 2;
    if (dp[i]) {
      ans++;
      freq[i]++;
    //   dbg(i);
    }
  }
  cout << ans << endl;
}