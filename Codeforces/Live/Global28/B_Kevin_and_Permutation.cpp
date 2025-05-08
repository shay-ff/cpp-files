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

#define int int64_t
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define rrep(i, a, b) for(int i = a; i >= b; --i)

//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

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

void pre_pro(){
}
/*
Given two positive integers 𝑛
 and 𝑘
, construct a permutation∗
 𝑝
 of length 𝑛
 to minimize the sum of the minimum values of all subarrays†
 of length 𝑘
. Formally, you need to minimize
*/
void dxt(int test_case){
    int n,k;
    cin >> n >> k;

    vector<int> p(n + 1, 0);
    int j = n/k + 1;
    int t = n/k;
    int x = 1;
    set<int> st;
    rep(i, 1, n + 1){
        if(i % k == 0){
            st.insert(i);
            p[i] = -1;
        }
        else{
            while(st.count(j)) ++j;
            p[i] = j;
            ++j;
        }
    }
    debug(p, x);
    rep(i, 1, n + 1){
        if(p[i] == -1){
            cout << x++ << " ";
            continue;
        }
        cout << p[i] << " ";
    }
    cout << endl;

}