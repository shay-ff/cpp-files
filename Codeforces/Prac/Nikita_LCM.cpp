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
// int gcd(int a, int b){
// 	return (b ? gcd(a, b % a) : a);
// }
int lcm(int a, int b){
	return (long long int)(a * b)/(__gcd(a, b));
}
void dxt(){
	int n; cin >> n;
	vector<int> ar(n);
	for(auto &x : ar){
		cin >> x;
	}
	if(n == 1){
		cout << 0 << endl;
		return;
	}
	int maxEle = *max_element(all(ar));
	int LCM = ar[0];
	for(int i = 1; i < n; ++i){
		LCM = lcm(LCM, ar[i]);
		if(LCM > maxEle){
			cout << n << endl;
			return;
		}
	}
	map<int,set<int>> div;
	for(int i = 0; i < n; ++i){
		int x = ar[i];
		for(int j = 1; j * j <= x; ++j){
			if(x % j == 0){
				div[x].insert(j);
				div[x].insert(x/j);
			}
		}
	}
	// debug(div);
	int ans = 0;
	for(auto &x : div[maxEle]){
		if(div.count(x)) continue;
		int _ans = 1, cntr = 0;
		vector<int> temp;
		for(auto &i : ar){
			if(x % i == 0){
				cntr++;
				temp.push_back(i);
			}
		}
		for(auto &i : temp){
			_ans = lcm(_ans, i);
		}
		if(_ans == x){
			setmax(ans, cntr);
		}
		// debug(x, _ans, cntr);
	}
	show(ans);
	// debug(div);

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