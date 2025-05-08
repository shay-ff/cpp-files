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
#define rep(i, b) for(int i = 0; i < b; ++i)
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
template<typename T> using MaxHeap = std::priority_queue<T>;
template<typename T> using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
void pre_pro(){
}
void dxt(int test_case){
	int n;
	cin >> n;
	vector<int> me(n), ilya(n);
	for(int i = 0; i < n; ++i){
		cin >> me[i];
	}
	for(auto &a : ilya){
		cin >> a;
	}

	sort(allr(me));
	sort(allr(ilya));
	int mes = 0, ilyas = 0, t = (n - (n/4));
	for(int i = 0; i < t; ++i){
		mes += me[i];
		ilyas += ilya[i];
	}

	if(mes >= ilyas){
		cout << 0 << endl;
	}
	else{
		int cntr = 0, idx = t - 1;
		while(ilyas > mes){
			n++; cntr++;
			if(n - (n/4) > t){
				mes += 100;
				if(t < n - cntr) ilyas += ilya[t];
				t++;
			}
			else if(idx >= 0){
				mes += 100;
				mes -= me[idx--];
			}
		}
		show(cntr);
	}

}















/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 

*/







