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
	int n, x;
	cin >> n >> x;

	vector<int> a(n), b(n);
	vector<pair<int,int>> _a(n), _b(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		_a[i] = {a[i], i};
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
		_b[i] = {b[i], i};
	}
	auto cmp = [&](pair<int,int> &t, pair<int,int> &q){
		return t.first < q.first;
	};
	sort(all(_a), cmp);
	sort(all(_b), cmp);
	debug(_a);
	debug(_b);
	vector<int> perm(n);
	int cntr = 0;
	for(int i = 0; i < n; ++i){
		perm[_a[i].second] = b[_b[(i + x) % n].second];
	}
	for(int i = 0; i < n; ++i){
		cntr += (a[i] > perm[i]);
	}
	if(cntr == x){
		cout << "YES\n";
		for(int i = 0; i < n; ++i){
			cout << perm[i] << " \n"[i == n - 1];
		}
	}
	else{
		cout << "NO\n";
	}
	debug(perm);
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