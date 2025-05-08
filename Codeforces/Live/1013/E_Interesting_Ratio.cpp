/**
*    created: 2025-03-25 20:46:59
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

const int maxm = 10000001;
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
int lcm(int a, int b){
    return a*b/__gcd(a, b);
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;
        int count = 0;

        for(int i = 0; i < primes.size() && primes[i] <= n; ++i){
            count += (n / primes[i]);
        }
        show(count);
    };
    sieve();
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}
// 1,p : such that p should be prime
// 2,p^2 : such that p should be prime
// t, t * p : such that p should be prime