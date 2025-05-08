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
	int n,q;
	cin>> n >> q;
	map<int,int> mp;
	vector<int> ar(n + 1, 0);
	for(int i = 1; i <= n; ++i){
		cin >> ar[i];
		mp[ar[i]] = i;
	}
	// map<int,int> cnt, ans;
	// int c = 0;
	// for(auto d : mp){
	// 	int k = d.first, v = d.second;
	// 	int s = c;
	// 	s += v;
	// 	if(s != v){
	// 		auto it = mp.lower_bound(k);
	// 		int dist = abs(k - it -> first);
	// 		ans[s] = dist;
	// 	}
	// 	c = s;
	// 	cnt[c]++;
	// }
	// debug(cnt);
	map<int,int> cnt;
	for(int i = 1; i <= n; ++i){
		int dif = (i - 1) * (n - i + 1) + (n - i);
		cnt[dif]++;
		if(i == n) continue;
		int points = ar[i + 1] - ar[i] - 1;
		if(points){
			int tot = i * (n - i);
			cnt[tot] += points;
		}

	}
	for(int i = 0; i < q; ++i){
		int k; cin >> k;
		if(cnt.count(k)) cout << cnt[k] << ' ';
		else cout << "0 ";
	}
	cout << endl;
	
}















