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
#define sz(x) (int)(x.size())
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353
/* "So do not lose heart nor fall into despair, for you will be superior if you are true in faith!" */
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
/*
You are given an array 𝑎1,𝑎2,…,𝑎𝑛
 of positive integers.

You can color some elements of the array red, but there cannot be two adjacent red elements (i.e., for 1≤𝑖≤𝑛−1
, at least one of 𝑎𝑖
 and 𝑎𝑖+1
 must not be red).

Your score is the maximum value of a red element plus the number of red elements. Find the maximum score you can get.
*/
void pre_pro(){
}
void dxt(int test_case){
	int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    int ans = 0;
    
    for(int i = 0; i < n; ++i){
        ans = max(ans, a[i]);
    }
    debug(ans);
    ans = max(ans + (n/2), ans + (n + 1)/2);
    show(ans);
}















