#include<bits/stdc++.h>
using namespace std;

void test_case(){
	int n;
	cin >> n;
 
	vector<int> ar(n);
	for(int i = 0; i < n; ++i){
		cin >> ar[i];
	}
 
	int mx = *max_element(ar.begin(),ar.end());
	sort(ar.begin(),ar.end());
	int ans = ar.front();
	if(n == 2){
		cout << (ar[0] + ar[1])/2 << endl;
		return;
	}
	
		for(int i = 1; i < n; ++i){
			ans = (ans + ar[i])/2;
		}
		cout << ans << endl;
}
int main(){
	int t; cin >> t;
	while(t--)
		test_case();

}