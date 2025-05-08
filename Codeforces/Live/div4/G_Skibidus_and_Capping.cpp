/**
*    created: 2025-02-10 00:43:27
**/
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

#define int long long
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define rrep(i, a, b) for(int i = a; i >= b; --i)

// order_of_key (k) : Number of items strictly smaller than k.
// find_by_order(k) : K-th element in a set (counting from zero).
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009, 1000000023, 1000000007, 998244353

template <class T> bool setmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template <class T> bool setmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}

void dxt(int test_case);
void pre_pro();
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    pre_pro();
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        dxt(i);
    }
    return 0;
}
const int maxm = 100100;
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
/*
Skibidus was abducted by aliens of Amog! Skibidus tries to talk his way out, but the Amog aliens don't believe him. To prove that he is not totally capping, the Amog aliens asked him to solve this task:

An integer 𝑥
 is considered a semi-prime if it can be written as 𝑝⋅𝑞
 where 𝑝
 and 𝑞
 are (not necessarily distinct) prime numbers. For example, 9
 is a semi-prime since it can be written as 3⋅3
, and 3
 is a prime number.

Skibidus was given an array 𝑎
 containing 𝑛
 integers. He must report the number of pairs (𝑖,𝑗)
 such that 𝑖≤𝑗
 and lcm(𝑎𝑖,𝑎𝑗)
∗
 is semi-prime.
*/
void pre_pro(){
    sieve();
}
void dxt(int test_case){
    int n;
    cin >> n;
    vector<int> ar(n);
    for(auto &x : ar){
        cin >> x;
    }
    int ans = 0;
    
}
// lcm(ai,aj) = p * q, p and q are prime
// how to calculate lcm(ai,aj) effectively?
// lcm(ai,aj) = ai * aj / gcd(ai,aj)
// gcd(ai,aj) = ai * aj / lcm(ai,aj)
// ai * aj = lcm(ai,aj) * gcd(ai,aj)
