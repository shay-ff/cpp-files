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

	vector<int> a(n);
	map<int,int> b;
	for(auto &x : a){
		cin >> x;
		b[x]++;
	}
	if(b.size() <= 3){
		cout << 0 << endl;
	} else{
		sort(a.begin(),a.end());
		a.resize(unique(a.begin(), a.end()) - a.begin());

	}
}
pair<int,int> findElement(int arrLen, int arr[], int target){
	pair<int,int> elementIndices = {-1,-1}; // base case if no pair exists
	map<int,int> hash;
	for(int index = 0; index < arrLen; ++index){
		int keyTofind = target - arr[index];
		if(hash.find(keyTofind) != hash.end()){
			elementIndices = {index, hash[keyTofind]};
			break;
		}
		hash[arr[index]] = index;
	}
	return elementIndices;
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
