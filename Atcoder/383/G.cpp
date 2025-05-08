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
template<typename T> using MaxHeap = std::priority_queue<T>;
template<typename T> using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
void dxt(int test_case){
	int n,k;
	cin >> n >> k;

	vector<int> ar(n + 1, 0);
	for(int i = 1; i <= n; ++i){
		cin >> ar[i];
		ar[i] += ar[i - 1];
	}
	auto get = [&](int i){
		return ar[i + k] - ar[i];
	};
	vector<int> ans;
	for(int j = 1; j <= n/k; ++j){
		MinHeap<int> pq;
		for (int i = 0; i <= n - k; i++) {
            int segment_sum = get(i);
            
            if (pq.size() < j) {
                pq.push(segment_sum);
            }
            else if (segment_sum > pq.top()) {
                pq.pop();
                pq.push(segment_sum);
            }
        }
        
        int max_total_sum = 0;
        while (!pq.empty()) {
            max_total_sum += pq.top();
            pq.pop();
        }
        
        ans.push_back(max_total_sum);
	}
	for(auto x : ans)
		cout << x << " ";
	cout << endl;

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
