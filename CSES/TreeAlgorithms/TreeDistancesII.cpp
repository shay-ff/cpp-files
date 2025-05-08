// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/1133
#include<bits/stdc++.h>
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
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353
// lb(x) : first greater or equal than x, ub(x) : first greater than x
template <class T> bool setmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template <class T> bool setmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
vector<int> adj[N];
int sub[N], in[N], out[N];
int n;

void dfs(int u, int p){
	sub[u] = 1;
	for(auto x : adj[u]){
		if(x != p){
			dfs(x, u);
			sub[u] += sub[x];
			in[u] += in[x] + sub[x];
		}
	}
}

void dfs1(int u, int p){
	int x = 0;
	for(auto c : adj[u]){
		if(c != p){
			x += in[c] + sub[c] * 2;
		}
	}

	for(int c : adj[u]){
		if(c != p){
			out[c] = (out[u] + 1 * (n - sub[u] + 1)) + (x - (in[c] + sub[c] * 2));
			dfs1(c, u);
		}

	}
}

void dxt(){
	cin >> n;

	for(int i = 1; i < n; ++i){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// dfs_in(1, -1);
	dfs(1, -1);
	dfs1(1, -1);
	for(int i = 1; i <= n; ++i){
		cout << in[i] + out[i] << " \n"[i == n];
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	startTime = clock();
	int T = 1;
	// cin >> T;
	for (int i = 1; i <= T; i++) {
		// debug("--- Case #%d start ---", i);
		//printf("Case #%d: ", i);
		dxt();
		//cout << dxt() << endl;
		// debug("--- Case #%d end ---", i);
		// debug("time = %.5lf ", getCurrentTime());
		// debug("++++++++++++++++++++");

	}

	return 0;
}