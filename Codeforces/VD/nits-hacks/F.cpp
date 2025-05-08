#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

void dxt(int test_case){
	double a, b, u, v;
    cin >> a >> b >> u >> v;

    int q;
    cin >> q;

    double ans = INF;
    int res = -1;
    
    for (int i = 0; i < q; ++i) {
        double x, y;
        cin >> x >> y;

        if (u == 0 || v == 0) continue;
        
        double p1 = (x - a) / u, p2 = (y - b) / v;
        double t = max(p1, p2);
        
        if (t >= 0 && t < ans) {
            ans = t;
            res = i + 1;
        }
    }
    cout << (ans == INF ? -1 : res) << endl;



}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
	    dxt(i);
	}
	return 0;
}




/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 
*/
