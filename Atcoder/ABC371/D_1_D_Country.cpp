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

void dxt(){
	int n;
    cin >> n;

    vector<int> X(n + 1), P(n + 1);
    for(int i = 1; i <= n; ++i) cin >> X[i];
    for(int i = 1; i <= n; ++i) cin >> P[i];

    map<int,int> t;
	for(int i = 1; i <= n; ++i){
		t[X[i]] = P[i];
	}
	sort(X.begin() + 1, X.end());
	for(int i = 1; i <= n; ++i){
		P[i] = t[X[i]];
	}
	// debug(X, P);
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        pref[i] = P[i];
        pref[i] += pref[i - 1];
    }
    // debug(pref);
    auto query = [&](int L, int R){
    	// debug(L, R);
        return pref[R] - (L ? pref[L - 1] : 0);
    };
  
    int Q;
    cin >> Q;
    while(Q--){
        int L, R;
        cin >> L >> R;
        int iL = lower_bound(X.begin() + 1, X.end(), L) - X.begin();
        int iR = upper_bound(X.begin() + 1, X.end(), R) - X.begin() - 1;
        if (iL > iR || iL > n || iR < 1) {
            cout << 0 << endl;
        } else {
            cout << query(iL, iR) << endl;
        }
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