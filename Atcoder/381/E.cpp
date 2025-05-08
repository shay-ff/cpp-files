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
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;

	vector<int> one(n + 1, 0), two(n + 1, 0), slash(n + 1, 0);
	auto make = [&](char ch, vector<int> &a){
		for(int i = 1; i <= (int)a.size(); i++){
			a[i] += a[i - 1] + (s[i - 1] == ch);
		}
	};
	make('1', one);
	make('2', two);
	make('/', slash);
	debug(one);
	debug(two);
	debug(slash);
	for(int i = 0; i < q; ++i){
		int L, R;
        cin >> L >> R;

        int total1 = one[R] - one[L - 1];
        int totalSlash = slash[R] - slash[L - 1];
        int total2 = two[R] - two[L - 1];

        if (totalSlash == 0) {
            cout << 0 << endl;
            continue;
        }

        int firstSlash = -1, lastSlash = -1;
        for (int i = L; i <= R; ++i) {
            if (s[i - 1] == '/') {
                if (firstSlash == -1) firstSlash = i;
                lastSlash = i;
            }
        }

        int left1 = one[firstSlash - 1] - one[L - 1];
        int right2 = two[R] - two[lastSlash];
        int result = 2 * min(left1, right2) + 1;

        cout << result << endl;
	}
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
