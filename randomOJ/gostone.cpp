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
void dxt(int test_case){
	int n;
	cin >> n;

	string s,p;
	cin >> s >> p;

	auto a = s, b = p;
	sort(all(a));
	sort(all(b));

	if(a != b){
		show(-1);
		return;
	}
	// cout << "here";
	n = s.size();
	s = s + "..";
	p = p + "..";

	queue<pair<string,int>> q;
	q.push({s, 0});
	map<string,int> vis;
	vis[s]++;
	while(!q.empty()){
		pair<string,int> temp = q.front();
		q.pop();
		string str = temp.first;
		int cnt = temp.second;
		// debug(str,cnt);
		if(str.substr(0, n) == p.substr(0, n)){
			cout << cnt << endl;
			return;
		}

		int fp = str.find('.'); 
		int sp = str.find('.', fp + 1);

		for(int i = 0; i <= n; ++i){
			if(str[i] != '.' && str[i + 1] != '.'){
				auto str1 = str;
				swap(str1[fp], str1[i]);
				swap(str1[sp], str1[i + 1]);
				str1[i] = '.';
				str1[i + 1] = '.';

				if(vis.find(str1) == vis.end()){
					vis[str1]++;
					q.push({str1, cnt + 1});
				}
			}
		}
	}
	show(-1);
}















/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 

*/







