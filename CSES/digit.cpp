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

void dxt(int test_case);
// void pre_pro();
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	// pre_pro();
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
	    dxt(i);
	}
	return 0;
}

using lli = long long int;
const int mod = 1e9 + 7;

lli add(lli a, lli b) {
    return (a % mod + b % mod) % mod;
}

lli mul(lli a, lli b) {
    return (a % mod * b % mod) % mod;
}

lli sub(lli a, lli b) {
    lli c = (a % mod - b % mod + mod) % mod;
    return c;
}
template<typename T> using MaxHeap = std::priority_queue<T>;
vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    vector<lli> pref(n + 1, 0);

    for(int i = 1; i <= n; ++i){
        pref[i] = arr[i - 1];
        pref[i] = add(pref[i], pref[i - 1]);
    }
    auto query = [&](int l, int r) -> lli{
    	if(l == 0) return 0;
    	if(r == 0) return 0;
        return sub(pref[r], pref[l - 1]);
    };
    vector<int> qans;
    for(auto &vec : queries){
        lli L = vec[0], R = vec[1];
        lli lsum = 0;
        if(L % n == 1){
        	lsum = 0;
        }
        else
        lli rsum = query(1, (R % n));
        L = (L + n - 1)/n; R = (R + n - 1)/n;
        lli tsum = mul((R - L)/n, pref.back());
        debug(L, R, lsum, rsum, tsum);
        qans.push_back(add(tsum, add(lsum, rsum)));
    }
    return qans;
}

void dxt(int test_case) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &x : arr) {
        cin >> x;
    }

    int q;
    cin >> q;

    vector<vector<lli>> que(q);
    for (int i = 0; i < q; ++i) {
        lli a, b;
        cin >> a >> b;
        que[i] = {a, b};
    }

    vector<int> ans = sumInRanges(arr, n, que, q);
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;
}











/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 

*/







