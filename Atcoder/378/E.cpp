#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int int64_t
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define rrep(i, a, b) for(int i = a; i >= b; --i)
 
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

template <class T> bool setmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template <class T> bool setmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}

void dxt(int test_case);
void pre_pro();
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	pre_pro();
	int T = 1;
	// cin >> T;
	for (int i = 1; i <= T; i++) {
	    dxt(i);
	}
	return 0;
}

void pre_pro(){
}
int M;
int add(int a, int b){
	int c = a + b;
	return c % M;
}
int sub(int a, int b){
	int c = a - b;
	return c < 0 ? c += M : c % M;
}
int mul(int a, int b){
	int c  = a % M * b % M;
	return c % M;
}
int getAllSubarraySumsModulo(vector<int>& arr, int m) {
        int n = arr.size();
        // Use prefix sum array to calculate subarray sums
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = (prefix[i] + arr[i]) % m;
        }
        
        // Count frequency of each remainder
        vector<int> count(m, 0);
        for(int i = 0; i <= n; i++) {
            count[prefix[i]]++;
        }
        
        int result = 0;
        // For each starting point
        for(int i = 0; i < n; i++) {
            // Decrease count of current prefix as we move forward
            count[prefix[i]]--;
            
            // For each possible value of mod m
            for(int mod = 0; mod < m; mod++) {
                // Find what remainder we need
                int target = (mod - prefix[i] + m) % m;
                // Add contribution of this remainder to result
                result += mod * count[target];
            }
        }
        
        return result;
    }
 int process(const vector<int>& list) {
    int n = list.size();
    int mod = M;
    vector<long long> preSum(n + 2, 0);
    deque<int> stack;
    long long pre = 0;
    long long result = 0;

    for (int i = 0; i <= n; i++) {
        int num = (i < n) ? list[i] : 0;
        pre = (pre + num) % mod;

        preSum[i + 1] = (preSum[i] + pre) % mod;
        while (!stack.empty() && list[stack.back()] > num) {
            int mid = stack.back();
            stack.pop_back();
            int left = stack.empty() ? -1 : stack.back();
            long long lSize = mid - left;
            long long rSize = i - mid;
            long long lSum = (left < 0) ? preSum[mid] : (preSum[mid] - preSum[left] + mod) % mod;
            long long rSum = (preSum[i] - preSum[mid] + mod) % mod;
            result = (result + (list[mid] * ((rSum * lSize - lSum * rSize) % mod)) % mod) % mod;
        }
        stack.push_back(i);
    }

    return (result + mod) % mod;
}
void dxt(int test_case){
	int n, m;
	cin >> n >> m;
	M = m;

	map<int,int> freq;
	freq[0] = 1;

	int ans = 0, sum = 0;
	vector<int> ar;
	for(int i = 1; i <= n; ++i){
		int x; cin >> x;
		ar.push_back(x);
		int pref = mul(x, i);
		int suff = mul(x, n - i + 1);
		debug(pref, suff);
		// sum = add(sum, add(pref, suff));
	}
	// cout << getAllSubarraySumsModulo(ar, m) << endl;
	cout << process(ar);
	// cout << sum << endl;



}















/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 

*/







