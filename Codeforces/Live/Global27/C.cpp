#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
void solve(vector<vector<int>>&ans, vector<int> &ar, int beg, int end){
  if(beg == end){
    ans.push_back(ar);
    return;
  }
  for(int i = beg; i <= end; i++){
    swap(ar[beg], ar[i]);
    solve(ans, ar, beg + 1, end);
    swap(ar[beg], ar[i]);
  }
}
void test_case(){
	int n; cin >> n;
	for(int i = 2; i <= 10; ++i){
		n = i;
		vector<int> ans(n, 0);
		iota(ans.begin(),ans.end(),1);
		vector<vector<int>> perm;
		solve(perm, ans, 0, n - 1);
		int t = 0;
		// debug(perm, ans);
		vector<int> a;
		for(auto &vec : perm){
			int k = 0;
			for(int i = 1; i <= n; ++i){
				if(i & 1){
					k &= vec[i - 1];
				} else{
					k |= vec[i - 1];
				}
			}
			if(k >= t){
				a = vec;
				t = k;
			}
		}
		cout << t << endl;
		for(auto &x  : a){
			cout << x << " ";
		}
		cout << endl;
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)
		test_case();

}