/**
*    created: 2025-02-15 20:50:00
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
There are four types of oysters, labeled 
1, 
2, 
3, and 
4. Exactly one of these types causes stomach trouble if eaten. The other types do not cause stomach trouble when eaten.

Takahashi ate oysters 
1 and 
2, and Aoki ate oysters 
1 and 
3. The information on whether each person got sick is given as two strings 
S 
1
​
  and 
S 
2
​
 . Specifically, 
S 
1
​
 = sick means Takahashi got sick, and 
S 
1
​
 = fine means Takahashi did not get sick. Likewise, 
S 
2
​
 = sick means Aoki got sick, and 
S 
2
​
 = fine means Aoki did not get sick.

Based on the given information, find which type of oyster causes stomach trouble.
*/
void pre_pro(){
}
void dxt(int test_case){
    string s1,s2;
    cin >> s1 >> s2;

    if(s1 != s2){
        if(s1 == "sick") cout << 2;
        else cout << 3;
    }
    else{
        if(s1 == "sick") cout << 1;
        else cout << 4;
    }
}