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
	int n,m,L;
	cin >> n >> m >> L;

	vector<pair<int,int>> ar(n);
	for(int i = 0; i < n; ++i){
		cin >> ar[i].first >> ar[i].second;
	}
	vector<pair<int,int>> br(m);
	for(int i = 0; i < m; ++i){
		cin >> br[i].first >> br[i].second;
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
