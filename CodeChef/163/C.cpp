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
	string s;
	cin >> s;

	int sum = 0;
	map<int,int> have; 
	int rsum = 0;
	for(int i = 0; i < s.size(); ++i){
		sum += (s[i] - '0');

		if(s[i] > '0' && s[i] <= '3'){
			have[s[i] - '0']++;
			rsum += (s[i] - '0') * (s[i] - '0') - (s[i] - '0');
		}
	}
	if(sum % 9 == 0){
		cout << "YES" << endl;
		return;
	}
	vector<int> ab;
	int cnt1 = 0, cnt2 = 0;
	for(auto & x : s){
		if(x == '2' && cnt1 < 10){
			int t = x - '0';
			ab.push_back(2);
			cnt1++;
		}
		if(x == '3' && cnt2 < 10){
			
			int t = x - '0';
			ab.push_back(9 - t);
			cnt2++;
		}
	}
	// debug(ab);
	vector<int> tsum;
	int t = ab.size();
	for(int i = 0; i < (1LL << t); ++i){
		int x = 0;
		for(int j = 0; j < t; ++j){
			if(i & (1LL << j)){
				x += ab[j];
			}
		}
		if((sum + x) % 9 == 0){
			// debug(sum + x, x);
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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




