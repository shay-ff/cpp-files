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
	int n, q;
	cin >> n >> q;

	vector<int> ar(n);
	const int d = 20;
	vector<vector<int>> rmq(n, vector<int>(d, INF / 8));
	for(int i = 0; i < n; ++i){
		cin >> ar[i];
		rmq[i][0] = ar[i];
	}

	for(int j = 1; j < d; ++j){
		for(int i = 0; i + (1 << j) - 1 < n; ++i){
			rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
		}
	}

	while(q--){
		int l, r;
		cin >> l >> r;
		--l,--r;
		int len = r - l + 1;
		int k = 0;
		while((1LL << k) <= len) k++;
		k--;
		cout << min(rmq[l][k], rmq[r - (1 << k) + 1][k]) << endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	// cin >> T;
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
