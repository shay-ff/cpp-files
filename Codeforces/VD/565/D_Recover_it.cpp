/**
*    created: 2025-01-28 21:42:35
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
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        dxt(i);
    }
    return 0;
}
/*
Authors guessed an array 𝑎
 consisting of 𝑛
 integers; each integer is not less than 2
 and not greater than 2⋅105
. You don't know the array 𝑎
, but you know the array 𝑏
 which is formed from it with the following sequence of operations:

Firstly, let the array 𝑏
 be equal to the array 𝑎
;
Secondly, for each 𝑖
 from 1
 to 𝑛
:
if 𝑎𝑖
 is a prime number, then one integer 𝑝𝑎𝑖
 is appended to array 𝑏
, where 𝑝
 is an infinite sequence of prime numbers (2,3,5,…
);
otherwise (if 𝑎𝑖
 is not a prime number), the greatest divisor of 𝑎𝑖
 which is not equal to 𝑎𝑖
 is appended to 𝑏
;
Then the obtained array of length 2𝑛
 is shuffled and given to you in the input.
Here 𝑝𝑎𝑖
 means the 𝑎𝑖
-th prime number. The first prime 𝑝1=2
, the second one is 𝑝2=3
, and so on.

Your task is to recover any suitable array 𝑎
 that forms the given array 𝑏
. It is guaranteed that the answer exists (so the array 𝑏
 is obtained from some suitable array 𝑎
). If there are multiple answers, you can print any.
*/
const int maxm = 3'000'000;
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

vector<int> divs;
void pre_pro(){
    sieve();
    divs.resize(200001);
    for(int i = 2; i < maxm; ++i){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
    for(int i = 1; i <= 200000; ++i){
        for(int j = 1; j * j <= i; ++j){
            if(i % j == 0){
                divs[i] = j;
            }
        }
    }
}
void dxt(int test_case){
    int n;
    cin >> n;
    vector<int> a(2 * n);
    rep(i,0,n){
        cin >> a[i];
    }
    vector<int> b;
    for(auto &x : a){
        if(x >= maxm) continue;
        if(is_prime[x]){
            b.push_back(primes[x - 1]);
        }else{
            b.push_back(divs[x]);
        }
    }
    for(auto &x : b){
        cout << x << " ";
    }

    


}