/**
*    created: 2025-03-19 20:41:28
**/
#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())
const int maxm = 100100100;
vector<int> primes;
bool is_prime[maxm];
void sieve() {
    fill(is_prime, is_prime + maxm, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < maxm; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i + i; j < maxm; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    sieve();
    int cntr = 0;
    for(int i : primes){
        cout << i << " ";
        cntr++;
        if(cntr % 50 == 0) cout << endl;
    }
    cout << endl;
}