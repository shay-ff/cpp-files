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

void pre_pro(){
}
void dxt(int test_case){
	int n, d, k;
	cin >> n >> d >> k;

	vector<int> ar(n + 3, 0);
	for(int i = 0; i < k; ++i){
		int l,r;
		cin >> l >> r;
		l = max(1LL, l - d + 1);
		ar[l]++;
		ar[r + 1]--;
	}
	for(int i = 1; i <= n; ++i)
		ar[i] += ar[i - 1];

	int mxm = -INF, mnm = INF, bro = 1, mom = 1;
	for(int i = 1;  i + d - 1 <= n; ++i){
		if(ar[i] > mxm){
			mxm = ar[i];
			bro = i;
		}
	}
	cout << bro << " ";

	for(int i = 1;  i + d - 1 <= n; ++i){
		if(ar[i] < mnm){
			mnm = ar[i];
			mom = i;
		}
	}
	cout << mom << endl;
}















