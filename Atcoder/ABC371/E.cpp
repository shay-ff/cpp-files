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

template <class T> struct BIT { //1-indexed
  int n; vector<T> t;
  BIT() {}
  BIT(int _n) {
    n = _n; t.assign(n + 1, 0);
  }
  T query(int i) {
    T ans = 0;
    for (; i >= 1; i -= (i & -i)) ans += t[i];
    return ans;
  }
  void upd(int i, T val) {
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) t[i] += val;
  }
  void upd(int l, int r, T val) {
    upd(l, val);
    upd(r + 1, -val);
  }
  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};
void dxt(){
	int n; cin >> n;
	map<int,set<int>> mp;
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		mp[x].insert(i);
		mp[x].insert(n);
	}
	int Tcont = n * (n + 1)/2;
	int ans = 0;

	for(auto x : mp){
		ans += Tcont;
		int prev = -1;
		for(auto i : x.second){
			int diff = i - prev - 1;
			int _ans = (diff * (diff + 1)/2);
			ans -= _ans;
			prev = i;
		}
	}
	cout << ans << endl;
	/*
	for(int i = 1; i <= n; ++i){
		if(occ[i].size()){
			if(occ[i].back() != n){
				occ[i].push_back(n);
			}
		}
	}
	debug(occ);
	auto search = [&](int idx, int key){
		int low = 0, high = occ[idx].size() - 1, ans;
		while(low <= high){
			int mid = (low + high)/2;
			if(occ[idx][mid] <= key){
				low = mid + 1;
			}
			else{
				ans = mid;
				high = mid - 1;
			}
		}
		return ans;
	};
	for(int i = 2; i <= n; ++i){
		int x = ar[i - 1];
		int idx = search(x, i - 1);
		debug(bit.query(i, n));
		bit.upd(i, occ[x][idx], -1);
		debug(bit.query(i, n));
		int t = bit.query(i, n);
		debug(x, occ[x][idx]);
		ans += t;
	}
	cout << ans << endl;
	*/
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