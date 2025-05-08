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
const int N = 200200, INF = 4e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

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
void dxt(int test_case){
	int n;
	cin >> n;

	vector<int> a(n);
	for(auto &x : a){
		cin >> x;
	}

	auto get = [&](vector<int> &a){
		int ans = 0;
		int n = (int)a.size();
		for(int i = 1; i < n; i += 2){
			setmax(ans, a[i] - a[i - 1]);
		}
		return ans;
	};

	if(n % 2 == 0){
		int ans = INF;
		setmin(ans, get(a));
		show(ans);
	}
	else{
		int ans = INF;
		for(int i = 0; i < n; ++i){
			int lb = 0, hb = 1e18;
			for(int j = a[i] - 1; j <= a[i] + 1; ++j){
				if(j < lb || j > hb || j == a[i]){
					continue;
				}
				auto b = a;
				if(find(all(b), j) != b.end())
					continue;
				b.push_back(j);
				sort(all(b));
				// debug(b, get(b));
				ans = min(ans, get(b));
			}
		}
		show(ans);
	}
}

/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 

*/







