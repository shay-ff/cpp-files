// time-limit: 1500
// problem-url: https://codeforces.com/contest/2005/problem/B1
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
	int n,m,q;
	cin >> n >> m >> q;

	multiset<int> M;
	for(int i = 0; i < m; ++i){
		int x;
		cin >> x;
		M.insert(x);
	}
	vector<int> Q(q);
	for(auto &x : Q){
		cin >> x;
	} 
	debug(Q, M);
	for(auto p : Q){
		auto Prev = M.lower_bound(p);
		if(Prev == M.end()){
			cout << n - *M.rbegin() << endl;
			continue;
		}
		if(Prev == M.begin()){
			cout << *M.begin() - 1 << endl;
			continue;
		}
		auto sPrev = prev(Prev);
		cout << (*Prev - *sPrev)/2 << endl;
	}
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