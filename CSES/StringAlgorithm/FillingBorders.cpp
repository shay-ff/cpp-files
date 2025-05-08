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
/*
A border of a string is a prefix that is also a suffix of the string but not the whole string. For example, the borders of abcababcab are ab and abcab.
Your task is to find all border lengths of a given string.
Input
The only input line has a string of length n consisting of characters a–z.
Output
Print all border lengths of the string in increasing order.
*/
void pre_pro(){
}
void dxt(int test_case){
    string s;
    cin >> s;

    string rev = s;
    reverse(all(rev));

    int n = sz(s);
    vector<int> Z(n), Zrev(n);
    int l = 0, r = 0;
    rep(i, 1, n){
        if(i <= r){
            Z[i] = min(r - i + 1, Z[i - l]);
        }
        while(i + Z[i] < n && s[Z[i]] == s[i + Z[i]]){
            Z[i]++;
        }
        if(i + Z[i] - 1 > r){
            l = i;
            r = i + Z[i] - 1;
        }
    }
    l = 0, r = 0;
    rep(i, 1, n){
        if(i <= r){
            Zrev[i] = min(r - i + 1, Zrev[i - l]);
        }
        while(i + Zrev[i] < n && rev[Zrev[i]] == rev[i + Zrev[i]]){
            Zrev[i]++;
        }
        if(i + Zrev[i] - 1 > r){
            l = i;
            r = i + Zrev[i] - 1;
        }
    }
    vector<int> ans;
    rep(i, 1, n){
        if(Z[i] + i == n){
            ans.push_back(Z[i]);
        }
    }
    rep(i, 1, n){
        if(Zrev[i] + i == n){
            ans.push_back(Zrev[i]);
        }
    }
    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
}