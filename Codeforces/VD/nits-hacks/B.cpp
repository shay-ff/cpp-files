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
const int N = 200200, INF = 8e18, MOD = 998244353; //   1000000009 , 1000000023 ,1000000007 , 998244353

template <class T> bool setmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template <class T> bool setmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}

void dxt(int test_case);
void pre_pro();
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	pre_pro();
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
	    dxt(i);
	}
	return 0;
}

void pre_pro(){
}
/*
As autumn graces Byteland, the trees will slowly shed their leaves†
. There is a tree with 𝑛
 nodes rooted at node 1
.


A tree leaf†
 is a non-root node with no children.

Each day of autumn, a leaf of the tree randomly falls off. If autumn lasts 𝑘
 days, can you find out the number of ways in which the leaves may fall off such that the tree is left with a height of ℎ
 after autumn fades away?

The height of a tree is the maximum number of nodes on the path from the root to any other node.

Since the answers can be large, print them modulo 998244353
.
*/
vector<int> adj[1001];
int add(int a, int b){
	int c = a % MOD + b % MOD;
	return c % MOD;
}
int dfs(int u, int h, int k){
	if(k == 0){
		if(h) return 0;
		return 1;
	}
	int res = 1;
	for(auto x : adj[u]){
		res = add(res, dfs(x, h - 1, k - 1));
	}

	return res;

}
void dxt(int test_case){
	int n,h,k;
	cin >> n >> k >> h;
	for(int i = 0; i <= n; ++i)
		adj[i].clear();
	for(int i = 0; i < n - 1; ++i){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = dfs(1, h,k);
	show(ans);
}















/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 

*/







