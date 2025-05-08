// time-limit: 2000
// problem-url: https://codeforces.com/contest/1977/problem/C
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
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
	int n;
	cin >> n;

	vector<int> ar(n + 1);
	set<int> uniq;
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		cin >> ar[i];
		uniq.insert(ar[i]);
		ans += uniq.size();
	}
	debug(ans);
	for(int i = 1; i < n; ++i){
		auto _u = uniq;
		_u.erase(ar[i]);
		int t = _u.size();
		int diff = uniq.size() - t;
		ans = ans + (i * n - (i * (i + 1))/2);
	}
	cout << ans << endl;

}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	startTime = clock();
	int T = 1;
	// cin >> T;
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