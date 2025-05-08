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
const int N = 2000100, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353


void dxt(int test_case){
	int n;
	cin >> n;
	int tg = sqrtl(n);
	vector<int> ar(tg + 1);
	for(int i = 1; i <= tg; ++i){
		ar[i] = i;
	}

	for(int i = 2; i * i <= tg; ++i){
		if(ar[i] == i){
			for(int j = i * i; j <= tg; j += i){
				if(ar[j] == j){
					ar[j] = i;
				}
			}
		}
	}
	int cntr = 0;
	for (int i = 2; i <= tg; i++) {
        int p = ar[i], q = ar[i / ar[i]];
        if (p * q == i && q != 1 && p != q) {
            cntr++;
        }
        else if (ar[i] == i) {
            if (pow(i, 8) <= n) {
                cntr++;
            }
        }
    }
    cout << cntr << endl;

}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	// cin >> T;
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
