/**
*    created: 2025-03-04 11:48:22
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
There are n banks, numbered from 1 to n. There are also n - 1 wires connecting the banks. All banks are initially online. Each bank also has its initial strength: bank i has initial strength ai.

Let us define some keywords before we proceed. Bank i and bank j are neighboring if and only if there exists a wire directly connecting them. Bank i and bank j are semi-neighboring if and only if there exists an online bank k such that bank i and bank k are neighboring and bank k and bank j are neighboring.

When a bank is hacked, it becomes offline (and no longer online), and other banks that are neighboring or semi-neighboring to it have their strengths increased by 1.

To start his plan, Inzane will choose a bank to hack first. Indeed, the strength of such bank must not exceed the strength of his computer. After this, he will repeatedly choose some bank to hack next until all the banks are hacked, but he can continue to hack bank x if and only if all these conditions are met:

Bank x is online. That is, bank x is not hacked yet.
Bank x is neighboring to some offline bank.
The strength of bank x is less than or equal to the strength of Inzane's computer.
Determine the minimum strength of the computer Inzane needs to hack all the banks.
*/
void pre_pro(){
}
void dxt(int test_case){
    int n;   
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<vector<int>> g(n);
    rep(i, 0, n - 1){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 2e9;

    multiset<int> st(all(a));
    for(int i = 0; i < n; i++){
        int currAns = a[i], nmx = -INF;
        st.erase(st.find(a[i]));
        for(auto &x : g[i]){
            st.erase(st.find(a[x]));
            nmx = max(nmx, a[x]);
        }
        setmax(currAns, nmx + 1);
        if(st.size()){
            setmax(currAns, *st.rbegin() + 2);
        }
        for(auto &x : g[i]){
            st.insert(a[x]);
        }
        st.insert(a[i]);
        ans = min(ans, currAns);
    }
    show(ans);
}