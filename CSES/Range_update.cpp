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
#define sz(x) (int)(x.size())
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define rep(i,a,b) for(int i = a; i < b; ++i)
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353
/* "So do not lose heart nor fall into despair, for you will be superior if you are true in faith!" */
template <class T> bool setmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template <class T> bool setmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}
 
void dxt(int test_case);
void pre_pro();
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	pre_pro();
	int T = 1;
	// cin >> T;
	for (int i = 1; i <= T; i++) {
	    dxt(i);
	}
	return 0;
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
void pre_pro(){
}
void dxt(int test_case){
	int n,k;
	cin >> n >> k;
 
	BIT<int> bit(n + 10);
	vector<int> ar(n + 2);
	rep(i, 1, n + 1){
		cin >> ar[i];
	}
 
	rep(i,0,k){
		int ty; cin >> ty;
 
		if(ty == 1){
			int a, b, u;
			cin >> a >> b >> u;
			bit.upd(a, b, u);
 
		} else{
			int p; cin >> p;
			cout << ar[p] + bit.query(p) << endl;
		}
	}
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
