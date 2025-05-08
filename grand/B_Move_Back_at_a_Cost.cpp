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

const int naxn = 1e6 + 10;
bool is_prime[naxn];
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

void dxt(int test_case){
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i = 2; i < n; ++i){
        if(is_prime[i]){
            mp[i]++;
        }
    }
    for(auto x : mp){
        if(mp.count(n - x.first)){
            cout << x.first << " " << n - x.first << endl;
            return;
        }
    }
    cout << -1 << endl;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    findPrimes();
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
