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
#define yesno(x) cout << ((x) ? "YES" : "NO") << endl
vector<int> fac(45, 0);
bool solve(int n, int x, int y){
	if(n == 1){
		return true;
	}
	if(fac[n - 1] <= y && fac[n] > y){
		return false;
	}
	if(fac[n] <= y) y -= fac[n];
	return solve(n - 1, y, x);
}
void dxt(int test_case){
	int n,fn,fn1;
	cin >> n >> fn >> fn1;

	yesno(solve(n, fn - 1, fn1 - 1));

}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	cin >> T;
	fac[0] = 1, fac[1] = 1;
	for(int i = 2; i <= 44; ++i){
		fac[i] = fac[i - 1] + fac[i - 2];
	}
	// debug(fac);
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
