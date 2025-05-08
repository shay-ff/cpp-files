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
	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		// printf("Case #%d: ", i);
	    dxt(i);
	}
	return 0;
}
const int naxn = 10001000;
bool is_prime[naxn + 10];
void findPrimes(){
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= naxn; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= naxn; j += i)
                is_prime[j] = false;
        }
    }
}
void pre_pro(){
    
}

int mul(int a, int b){
    return (long long)(a % MOD * b % MOD) % MOD;
}
void dxt(int test_case){
    cout << "Case #" << test_case << ": ";
    int W, G, L;
    cin >> W >> G >> L;

    int ans;
    if(L > 0){
        int f = (W - G) % MOD, sec = (2 * (L % MOD) + 1) % MOD;
        ans = mul(f,sec);
    }
    else{
        ans = (W - G) % MOD;
    }
    show(ans);
}















/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 

*/







