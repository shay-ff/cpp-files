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
	int n,k;
	cin >> n >> k;

	vector<long long> ar;
    bool is = false; int idx = -1;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if(x >= k){
            if(x == k){
                is = true;
                idx = i + 1;
            }
            ar.push_back(x);
        }
    }
    if(is){
        cout << "YES\n1\n" << idx << endl;
        return;
    }
    n = ar.size();
    if(!ar.size()){
        cout << "No\n";
        return;
    }
 	auto make = [&](int l, int r){
 		vector<int> a;
 		for(int i = l; i < r; ++i)
 			a.push_back(ar[i]);
 		return a;
 	};
	vector<int> left = make(0, n/2);
	vector<int> right = make(n/2, n);

	debug(left, right);
	auto solve = [&](vector<int> &a, int b){
		int m = a.size();
		vector<pair<int,vector<int>>> mai;
		for(int i = 0; i < (1LL << m); ++i){
			int currand = -1; vector<int> temp;
			for(int j = 0; j < m; ++j){
				if(i & (1<<j)){
					if(temp.empty()){
						currand = a[j];
						if(b)
						temp.push_back(n/2 + j);
					}
					else{
						currand &= a[j];
						if(b)
						temp.push_back(n/2 + j);
					}
				}
			}
			if(currand == -1)
				continue;
			mai.push_back({currand, temp});
		}
		return mai;
	};
	vector<pair<int,vector<int>>> leftand= solve(left, 0);
	vector<pair<int,vector<int>>> rightand= solve(right, 1);
	for(int i = 0; i < leftand.size(); ++i){
		int andi = leftand[i].first;
		auto a = leftand[i].second;
		if(andi == k){
				cout << "YES\n";
				cout << a.size()<< endl;
				for(auto x : a)
					cout << x << " ";
				cout << endl;
				return;
			} 

	}
	for(int i = 0; i < rightand.size(); ++i){
		int andi = rightand[i].first;
		auto a = rightand[i].second;
		if(andi == k){
				cout << "YES\n";
				cout << a.size()<< endl;
				for(auto x : a)
					cout << x << " ";
				cout << endl;
				return;
			} 

	}
	debug(leftand, rightand);
	for(int i = 0; i < rightand.size(); ++i){
		for(int j = 0; j < leftand.size(); ++j){
			int andi = rightand[i].first, andj = leftand[j].first;
			auto a = rightand[i].second, b = leftand[j].second;
			if((andi & andj) == k){
				cout << "YES\n";
				cout << a.size() + b.size() << endl;
				for(auto x : a)
					cout << x << " ";
				for(auto x : b)
					cout << x << " ";
				cout << endl;
				return;
			} 
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




/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 
*/
