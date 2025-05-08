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
#define sz(s) (int)s.size()
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
	auto query = [&](string a){
		cout << "? " << a << endl;
		int o;
		cin >> o;

		return o;
	};
	int n;
	cin >> n;
	string ans = "";
	while(sz(ans) < n){
		if(query(ans + "0")){
			ans += "0";
			continue;
		}
		if(query(ans + "1")){
			ans += "1";
			continue;
		}
		break;
	}

	while(sz(ans) < n){
		if(query("0" + ans)){
			ans = '0' + ans;
			continue;
		}
		else{
			ans = "1" + ans;
			continue;
		}
		break;
	}
	cout << "! " << ans << endl;
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
} /* "So do not lose heart nor fall into despair, for you will be superior if you are true in faith!" */