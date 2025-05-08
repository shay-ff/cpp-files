/**
*    created: 2025-03-08 17:32:55
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
There are 
N black balls and 
M white balls.
Each ball has a value. The value of the 
i-th black ball (
1≤i≤N) is 
B 
i
​
 , and the value of the 
j-th white ball (
1≤j≤M) is 
W 
j
​
 .

Choose zero or more balls so that the number of black balls chosen is at least the number of white balls chosen.
 Among all such choices, find the maximum possible sum of the values of the chosen balls.
*/

void pre_pro(){
}
void dxt(int test_case){
    int n, m;
    cin >> n >> m;
    vector<int> b(n), w(m);
    
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int j = 0; j < m; j++)
        cin >> w[j];

    vector<int> pb, nb, pw;
    for (int i = 0; i < n; i++){
        if (b[i] > 0)
            pb.push_back(b[i]);
        else
            nb.push_back(b[i]);
    }
    
    int ans = accumulate(pb.begin(), pb.end(), 0LL), pbs = pb.size();
    for (int j = 0; j < m; j++){
        if (w[j] > 0)
            pw.push_back(w[j]);
    }
    sort(allr(pw));
    int xtra = min(pbs, sz(pw));
    for (int i = 0; i < xtra; i++){
        ans += pw[i];
    }
    
    vector<int> temp;
    int t = pw.size();
    for (int i = xtra; i < t; i++){
        temp.push_back(pw[i]);
    }
    sort(allr(nb));
    
    int x = min(temp.size(), nb.size());
    for (int i = 0; i < x; i++){
        if (nb[i] + temp[i] > 0)
            ans += (nb[i] + temp[i]);
        else
            break;
    }
    
    show(ans);
}