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
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        dxt(i);
    }
    return 0;
}

void pre_pro(){
}
void dxt(int test_case){
    int a,b,c;
    cin >> a >> b >> c;
    
    // a -> count of set bits in A
    // b -> count of set bits in B
    // C -> A ^ B
    int c_bits = 0;
    vector<int> highestp2;
    rep(i, 0, 60){
        if(c & (1LL << i)){
            c_bits++;
            highestp2.push_back(i); 
        }
    }
    // debug(highestp2, vec);
    int el_a = 0, el_b = 0, idx = 0;
    for(int i = 0; i < 60; ++i){
        if(binary_search(all(highestp2), i)) continue;
        if(a == 0 && b == 0) break;
        if(a + b == c_bits) break;
        el_a |= (1LL << i);
        el_b |= (1LL << i);
        a--;
        b--;
    }
    while(a > 0 && idx < highestp2.size()){
        el_a |= (1LL << highestp2[idx]);
        a--;
        idx++;
    }
    while(b > 0 && idx < highestp2.size()){
        el_b |= (1LL << highestp2[idx]);
        b--;
        idx++;
    }
    if((el_a ^ el_b) != c){
        cout << -1 << endl;
        return;
    }
    if(a == 0 && b == 0){
        cout << el_a << " " << el_b << endl;
    }
    else cout << -1 << endl;

}