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
	int n,k;
	cin >> n >> k;

	vector<int> ar(n);
	int tc = 0;
	for(auto &x : ar){
		cin >> x;
		tc += x;
	}
	int mx = *max_element(all(ar));
	// debug(tc);
	// auto ok = [&](int mid){
	// 	int mxr = 0;
	// 	for(int i = 0; i < n; ++i){
	// 		mxr += (ar[i] < mid ? mid - ar[i] : 0);
	// 		if(mxr > k)
	// 			return false;
	// 	}
	// 	// debug(mxr);
	// 	return true;
	// };
	// int low = 1, high = (tc + k)/n, ans = 0, mid;;
	// while(low <= high){
	// 	mid = low + (high - low)/2;
	// 	// debug(mid);
	// 	if(ok(mid)){
	// 		ans = mid;
	// 		low = mid + 1;
	// 	}
	// 	else{
	// 		high = mid - 1;
	// 	}
	// }
	vector<int> can(n);
	for(int i = n - 1; i >= 0; --i){
		can[i] = (tc + k)/(i + 1);
	}
	for(int i = n - 1; i >= 0; --i){
		if((can[i] < mx))
			continue;
		show(i + 1);
		break;
	}
}
















