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
There is a shop that sells action figures near Monocarp's house. A new set of action figures will be released shortly; this set contains 𝑛
 figures, the 𝑖
-th figure costs 𝑖
 coins and is available for purchase from day 𝑖
 to day 𝑛
.

For each of the 𝑛
 days, Monocarp knows whether he can visit the shop.

Every time Monocarp visits the shop, he can buy any number of action figures which are sold in the shop (of course, he cannot buy an action figure that is not yet available for purchase). If Monocarp buys at least two figures during the same day, he gets a discount equal to the cost of the most expensive figure he buys (in other words, he gets the most expensive of the figures he buys for free).

Monocarp wants to buy exactly one 1
-st figure, one 2
-nd figure, ..., one 𝑛
-th figure from the set. He cannot buy the same figure twice. What is the minimum amount of money he has to spend?

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer 𝑛
 (1≤𝑛≤4⋅105
) — the number of figures in the set (and the number of days);
the second line contains a string 𝑠
 (|𝑠|=𝑛
, each 𝑠𝑖
 is either 0 or 1). If Monocarp can visit the shop on the 𝑖
-th day, then 𝑠𝑖
 is 1; otherwise, 𝑠𝑖
 is 0.
*/
void pre_pro(){
}
void dxt(int test_case){
    int n;
    cin >> n;

    string s;
    cin >> s;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    vector<int> off, on;

    rep(i, 0, n){
        if(s[i] == '0') off.push_back(i);
        else on.push_back(i);
    }   
    auto can  = [&](int mid){
        vector<int> vis(n, 0);
        for(int i = n - 1; i >= 0; --i){
            if(mid > 0 && s[i] == '1'){
                vis[i] = 1;
                mid--;
            }
        }
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(vis[i]){
                res--;
                if(res < 0) return false;
            }
            else{
                res++;
            }
        }
        return true;
    };
    int ans = 0;
    int l = 1, r = on.size() + 1;
    while(l + 1 < r){
        int mid = l + (r - l)/2;
        if(can(mid)){
            l  = mid;
        } else{
            r = mid;
        }
    }
    for(int i = n - 1; i >= 0; --i){
        if(l > 0 && s[i] == '1'){
            l--;
        }
        else{
           ans += i + 1;
        }
    }
    cout << ans << endl;

}