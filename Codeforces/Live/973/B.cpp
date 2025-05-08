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

	vector<int> ar(n);
	for(int i = 0; i < n; ++i){
		cin >> ar[i];
	}
	if(n == 2){
		cout << ar[1] - ar[0] << endl;
		return;
	}
	int ans = 0;
	vector<int> temp;
	for(int i = 0; i < n - 2; ++i)
		temp.push_back(ar[i]);
	sort(all(temp));
	debug(temp);
	for(int i = 0; i < temp.size(); ++i){
		ans = (ar[n - 2] - temp[i]);
		ar[n - 2] = ans;
	}
	debug(ans);
	cout << ar.back() - ans << endl;

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