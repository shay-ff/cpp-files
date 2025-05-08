#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

void dxt(int test_case){
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> c(n + 1);
	vector<int> pref(n + 1, 0);
	for(int i = 1; i <= n; ++i){
		cin >> c[i];
	}
	sort(c.begin() + 1, c.end());
	for(int i = 1; i <= n; ++i){
		pref[i] = pref[i - 1] + c[i];
	}
	vector<int> ans(n + 1, 0);
	for(int i = 1; i <= k; ++i)
		ans[i] = c[i];
	// debug(ans);
	for(int i = n; i > k; --i){
		int j = i - (k);
		// debug(j);
		int sum = 0;
		while(j >= 1){
			sum += c[j];
			j -= (k + 1);
		}
		ans[i] = sum;
	}
	for(int i = 1; i <= n; ++i){
		if(i <= k){
			cout<< pref[i] << " ";
 		} else{
			int t = pref[i];
			// debug(t);
			cout << t - ans[i] << " ";
		}
	}
	cout << endl;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
	    dxt(i);
	}
	return 0;
}




/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 
*/
