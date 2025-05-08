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
void dxt(int test_case){
    int n;
    cin >> n;

    vector<int> ar(n + 1);
    rep(i, 1, n + 1){
        cin >> ar[i];
    }
    vector<array<int,2>> val(n + 1);
    for(int i = 1; i <= n; ++i){
        val[i][0] = ar[i];
        val[i][0] += i - 1;
        val[i][1] = i - 1;
    }
    // debug(val);
    int cntr = n;
    val[1][0] = 0;
    sort(val.begin(), val.end());
    multiset<int> st{n};
    for(int i = 2; i <= n; ++i){
        if(st.count(val[i][0])){
            setmax(cntr, val[i][0] + val[i][1]);
            st.insert(val[i][0] + val[i][1]);
        }
    }
    // debug(st);
    show(cntr);


}


// ai = n - i + 1
// ai + i - 1 = n












/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 

*/







