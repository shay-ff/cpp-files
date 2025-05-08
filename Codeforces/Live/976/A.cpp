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
	cin >> T;
	for (int i = 1; i <= T; i++) {
	    dxt(i);
	}
	return 0;
}
int powrr(int a, int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = res* a;
		}
		a = (a* a);
		b >>= 1;
	}
	return res;
}
void pre_pro(){
}
int job(int n, int k){
	if(n == 0)
		return 0;
	if(n < k)
		return n;
	int ans = 0, t = n;
	while(n){
		ans++;
		n/= k;
	}
	if(powrr(k, ans) > t)
		--ans;
	int rem = t - powrr(k, ans);
	return 1LL + job(rem, k);
}

void dxt(int test_case){
	int n,k;
	cin >> n >> k;

	if(k == 1 || n < k){
		cout << n << endl;
		return;
	}
	// int ans = 0;
	// while(n){
	// 	ans += (n % k);
	// 	n /= k;
	// }
	cout << job(n,k) << endl;
	
}















