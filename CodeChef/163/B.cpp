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
	int n; cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	if(sum % n != 0){
		cout << "NO\n";
		return;
	}

	vector<int> ev, od;
	int evs = 0, ods = 0;
	for(int  x= 0; x < n; ++x){
		if(x & 1 ^ 1) ev.push_back(a[x]), evs += a[x];
		else od.push_back(a[x]), ods += a[x];
	}
	sum /= n;
	debug(evs, ods,sum, ev,od);
	if(((ev.size() * sum) == evs) && ((od.size() * sum) == ods)){
		cout << "YES\n";

	} else cout << "NO\n";
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
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
