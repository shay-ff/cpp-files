/**
*    created: 2024-12-27 03:44:31
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
template <class T> T fsqrt(T n) {
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
    cin >> n ;

    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
    }
    int cntr1 = 0, cntr2 = 0;
    for(int i = 0; i < n; ++i){
        int x = fsqrt(a[i]);
        if(x * x == a[i]){
            cntr1++;
        }else{
            cntr2++;
        }
    }
    if(cntr1 == cntr2){
        cout << "0\n";
        return;
    }
    vector<int> tomake, tonotmkae;
    tomake.resize(n, 0);
    tonotmkae.resize(n, 0);

    for(int i = 0; i < n; ++i){
        int x = fsqrt(a[i]);
        if(x * x == a[i]){
            tomake[i] = 0;
            if(a[i] == 0){
                tonotmkae[i] = 2;
            }else{
                tonotmkae[i] = 1;
            }
        }
        else{
            tonotmkae[i] = 0;
            tomake[i] = min(abs((x + 1) * (x + 1) - a[i]), abs(a[i] - x * x));
        }
    }
    
    sort(all(tomake));
    sort(all(tonotmkae));
    // debug(tomake, cntr1);
    // debug(tonotmkae, cntr2);
    if(cntr1 > cntr2){
        int req = (cntr1 - cntr2) / 2;
        int ans = 0, have = 0;
        for(int i = 0; i < n && have != req; ++i){
            if(tonotmkae[i] == 0)
                continue;
            ans += tonotmkae[i];
            have++;
        }
        cout << ans << endl;
    }
    else{
        int req = (cntr2 - cntr1) / 2;
        int ans = 0, have = 0;
        for(int i = 0; i < n && have != req; ++i){
            if(tomake[i] == 0)
                continue;
            ans += tomake[i];
            
            have++;
        }
        cout << ans << endl;
    }
}