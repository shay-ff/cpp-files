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

	vector<int> pos, neg;
	int z = 0;

	for(int i = 0; i < n; ++i){
		int c; cin >> c;

		if(c > 0){
			pos.push_back(c);
		} else if(c < 0){
			neg.push_back(c);
		} else{
			z++;
		}
	}
	sort(pos.rbegin(),pos.rend());
	sort(neg.rbegin(),neg.rend());
	int i = 0, j = 0;
	int sum = 0;
	while(i < (int)pos.size() && j < (int)neg.size() && z > 0){
		if(pos[i] > abs(neg[j])){
			sum += pos[i];
			++i;
		} else{
			sum += neg[j];
			++j;
		}
	}
	vector<int> b,c;

	for(; i < pos.size(); ++i) b.push_back(pos[i]);
	for(; j < neg.size(); ++j) c.push_back(neg[j]);

	for(int j = 0, i = (int)c.size() - 1; j < (int)b.size() && i >= 0; ++j,--i){
		sum += abs(b[j] - c[i]);
	}
	// now check whether pos and 
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
