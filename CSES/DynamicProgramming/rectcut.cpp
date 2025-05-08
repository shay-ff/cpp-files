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
const int N = 200200, INF = 1e9, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

template <class T> bool setmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template <class T> bool setmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}

void dxt();
void pre_pro();
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	pre_pro();
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
	    dxt();
	}
	return 0;
}

void pre_pro(){
}
const int maxm = 555;
int dp[maxm][maxm];
void dxt(){
	int a, b;
	cin >> a >> b;

	for(int i = 0; i <= a; ++i){
		for(int j = 0; j <= b; ++j){
			if(i == j){
				dp[i][j] = 0;
			}
			else{
				dp[i][j] = INF;
				for(int c = 1; c < i; ++c){
					setmin(dp[i][j], dp[i - c][j] + dp[c][j] + 1);
				}
				for(int c = 1; c < j; ++c){
					setmin(dp[i][j], dp[i][j - c] + dp[i][c] + 1);
				}
			}
		}
	}
	cout << dp[a][b] << endl;

}















/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 

*/







