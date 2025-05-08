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
	int n,m;
	cin >> n >> m;

	vector<vector<char>> S(n, vector<char> (n)), T(m, vector<char> (m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> S[i][j];
		}
	}
	for(int j = 0; j < m; ++j){
		for(int i = 0; i < m; ++i){
			cin >> T[j][i];
		}
	}

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
