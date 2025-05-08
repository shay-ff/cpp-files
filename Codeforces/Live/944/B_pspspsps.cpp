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
/*
Given a string 𝑠=𝑠1𝑠2…𝑠𝑛
 of length 𝑛
 consisting of characters p, s, and . (dot), determine whether a permutation∗
 𝑝
 of length 𝑛
 exists, such that for all integers 𝑖
 (1≤𝑖≤𝑛
):

If 𝑠𝑖
 is p, then [𝑝1,𝑝2,…,𝑝𝑖]
 forms a permutation (of length 𝑖
);
If 𝑠𝑖
 is s, then [𝑝𝑖,𝑝𝑖+1,…,𝑝𝑛]
 forms a permutation (of length 𝑛−𝑖+1
);
If 𝑠𝑖
 is ., then there is no additional restriction.
*/
void pre_pro(){
}
void dxt(int test_case){
    int n;
    cin >> n;

    string s;
    cin >> s;
    if(count(all(s), 'p') == 0 || count(all(s), 's') == 0){
        cout << "YES\n";
        return;
    }
    int ss = -1, sp = -1;
    if(s[0] == 's') s[0] = '.';
    for(int i = 0; i < n; ++i){
        if(s[i] == 's'){
            ss = i;
            break;
        }
    }
    s[n - 1] = '.';
    for(int i = n - 1; i >= 0; --i){
        if(s[i] == 'p'){
            sp = i;
            break;
        }
    }
    if(ss != -1 && sp != -1){
        cout << "NO\n";
    }else{
        cout << "YES\n";
    }
}