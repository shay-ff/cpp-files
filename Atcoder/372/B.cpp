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
int64_t fastPow(int64_t a, int64_t b) {
    int64_t res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

vector<int> ans;
int n;

void solve(int u) {
    if (u == 0)
        return;
    int c = 0;
    int x = u;
    while (x) {
        c++;
        x /= 3;
    }
    if (fastPow(3, c) > u) {
        c--;
    }
    int rem = u - fastPow(3, c);
    ans.push_back(c);
    solve(rem);
}

void dxt() {
    ans.clear();
    cin >> n;
    solve(n);
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << endl;
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
} /* "So do not lose heart nor fall into despair, for you will be superior if you are true in faith!" */