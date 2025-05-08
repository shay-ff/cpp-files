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

	string s;
	cin >> s;

	int a = 0, b = 0;
	for(auto c : s){
		if(c == 'S') a -= 1;
		else if(c == 'N') a += 1;

		if(c == 'E') b += 1;
		else if(c == 'W') b -= 1;
	}

	if(a & 1 || b & 1){
		cout << "NO\n";
		return;
	}
	string ans(n, 'H');
	auto check = [&](string ans) -> bool {
	    pair<int, int> r{0, 0}, h{0, 0};
	    map<char, pair<int, int>> dire = {
	        {'S', {1, 0}},
	        {'N', {-1, 0}},
	        {'E', {0, 1}},
	        {'W', {0, -1}}
	    };

	    for(int i = 0; i < n; ++i){
	    	if(ans[i] == 'R'){
	    		r.first += dire[s[i]].first;
	    		r.second += dire[s[i]].second;
	    	} else{
	    		h.first += dire[s[i]].first;
	    		h.second += dire[s[i]].second;
	    	}
	    }
	    debug(r, h);
	    return r == h;
	};
	if(a == 0 && b == 0){
		if(n == 2){
			cout << "NO\n";
			return;
		}
		int ok = 0;
		char taken = '*';
		int i = 0;
		while(s[i] != 'N') ++i;
		ans[i] = 'R';
		i = 0;
		while(s[i] != 'S') ++i;
		ans[i] = 'R';
		ok |= ans.find('R') != string::npos;
		
		debug(ok);
		if(ok == 0){
			int i = 0;
			while(s[i] != 'W') ++i;
			ans[i] = 'R';
			i = 0;
			while(s[i] != 'E') ++i;
			ans[i] = 'R';
		}
		
	}
	else{

		for(int i = 0; i < n; ++i){
			if(s[i] == 'N' && a > 0){
				a -= 2;
				ans[i] = 'R';
			}
			else if(s[i] == 'S' && a < 0){
				a += 2;
				ans[i] = 'R';
			}
			if(s[i] == 'E' && b > 0){
				b -= 2;
				ans[i] = 'R';
			}
			else if(s[i] == 'W' && b < 0){
				b += 2;
				ans[i] = 'R';
			}
		}
	}
	assert(check(ans));
	cout << ans << endl;

}















/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 

*/







