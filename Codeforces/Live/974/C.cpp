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

	vector<int> ar(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        sum += ar[i];  
    }
    sort(all(ar));
    if (n == 1) {
        show(-1);
        return;
    }
    int mxm = *max_element(all(ar));
    int low = 0, high = INF, ans = -1;
    
    auto chk = [&](int mid)->bool{
    	int _sum = sum + mid;
    	ar[n - 1] += mid;
    	long double nvg = _sum/(long double)n;
    	long double th = (long double)nvg/2.0;
    	int cnt = 0;
    	for(int i = 0; i < n; ++i){
    		if(ar[i] < th)
    			cnt++;
    	}
    	return cnt > n/2;
    };

   	while(low <= high) {
   		int mid = low + (high - low)/2;
   		if(chk(mid)){
   			ans = mid;
   			high = mid-1;
   		}
   		else{
   			low = mid + 1;
   		}
   	}
   	if(ans > 1e14) ans = -1;
   	cout << ans << endl;

}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	startTime = clock();
	int T = 1;
	cin >> T;
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