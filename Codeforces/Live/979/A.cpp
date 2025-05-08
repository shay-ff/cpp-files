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
	cout << 1 << " ";
	int x = 200000;
	cout << x << " ";
	cout << 6 << " " << 33333 << " ";
	vector<int> evil = {541, 1109, 2357, 5087, 10273, 20753, 42043, 85229, 172933};
	int n = evil.size();
	for(int i = 0; i < x - 2; x++){
		cout << evil[(i % n)] << " ";
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	// cout << T << " ";
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
