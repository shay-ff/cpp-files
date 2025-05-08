/**
*    created: 2025-01-25 18:03:22
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
N foods, each containing exactly one of vitamins 
1, 
2, and 
3.
Specifically, eating the 
i-th food gives you 
A 
i
​
  units of vitamin 
V 
i
​
 , and 
C 
i
​
  calories.

Takahashi can choose any subset of these 
N foods as long as the total calorie consumption does not exceed 
X.
Find the maximum possible value of this: the minimum intake among vitamins 
1, 
2, and 
3.
*/
void pre_pro(){
}
const int maxm = 5050;
void dxt(int test_case){
    int n,x;
    cin >> n >> x;
    vector<vector<pair<int,int>>> ar(4);
    for(int i = 0; i < n; ++i){
        int v,a,c;
        cin >> v >> a >> c;
        ar[v - 1].push_back({a,c});
    }
    vector<vector<int>> dp(4, vector<int>(x + 2, 0));
    for(int i = 0; i < 3; ++i){
        for(auto &p : ar[i]){
            for(int j = x; j >= 0; --j){
                if(j - p.second >= 0){
                    dp[i][j] = max(dp[i][j], dp[i][j - p.second] + p.first);
                }
            }
        }
    }
    int low = 0, high = INF;
    int ans = high;
    while(low <= high){
        int mid = (low + high) / 2;
        int id1 = lower_bound(all(dp[0]), mid) - dp[0].begin();
        int id2 = lower_bound(all(dp[1]), mid) - dp[1].begin();
        int id3 = lower_bound(all(dp[2]), mid) - dp[2].begin();
        if(id1 + id2 + id3 <= x){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    show(ans);
}