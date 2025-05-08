/**
*    created: 2025-02-28 20:54:47
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
template <class T> T _sqrt(T n) {
    T lo = 0, hi = n;
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        if (mid * mid <= n) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}
void pre_pro(){
}
void dxt(int test_case){
    int n;
    cin >> n;

    if(n == 1){
        cout << -1 << endl;
        return;
    }
    vector<int> a;
    for(int i = 0, even = 2, odd = 1; i < n; ++i){
        if(i & 1 ^ 1){
            a.push_back(even);
            even += 2;
        }
        else{
            a.push_back(odd);
            odd += 2;
        }
        // debug(i, even, odd, a);
    } 
    if(n & 1)
    {a.pop_back();
    a.push_back(n);}
    auto check = [&](vector<int> &a){
        int sum = 0;
        for(int i = 0; i < a.size(); ++i){
            sum += a[i];
            int sq = _sqrt(sum);
            if(sq * sq == sum){
                cout << "has : " << sum<< endl;
                return false;
            }
        }
        return true;
    };
    debug(check(a));
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}