/**
*    created: 2025-01-28 21:30:21
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
/*
You are given an integer 𝑛
.

You can perform any of the following operations with this number an arbitrary (possibly, zero) number of times:

Replace 𝑛
 with 𝑛2
 if 𝑛
 is divisible by 2
;
Replace 𝑛
 with 2𝑛3
 if 𝑛
 is divisible by 3
;
Replace 𝑛
 with 4𝑛5
 if 𝑛
 is divisible by 5
.
For example, you can replace 30
 with 15
 using the first operation, with 20
 using the second operation or with 24
 using the third operation.

Your task is to find the minimum number of moves required to obtain 1
 from 𝑛
 or say that it is impossible to do it.

You have to answer 𝑞
 independent queries.
*/

void pre_pro(){
}
void dxt(int test_case){
    int n; cin >> n;
    int ans = 0;
    while(n != 1){
        if(n % 2 == 0){
            n /= 2;
        }else if(n % 3 == 0){
            n /= 3;
            n *= 2;
        }else if(n % 5 == 0){
            n /= 5;
            n *= 4;
        }else{
            ans = -1;
            break;
        }
        ans++;
    }
    show(ans);
}