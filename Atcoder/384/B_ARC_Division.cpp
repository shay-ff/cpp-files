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
AtCoder Regular Contest (ARC) is divided into two divisions.

In ARC Div. 
1, participants whose rating at the start of the contest is between 
1600 and 
2799, inclusive, are subject to rating updates.
In ARC Div. 
2, participants whose rating at the start of the contest is between 
1200 and 
2399, inclusive, are subject to rating updates.
Takahashi decided to participate in 
N ARCs.

Initially, his rating is 
R.

The 
i-th 
(1≤i≤N) ARC is Div. 
D 
i
​
 , and his performance in that contest is represented by an integer 
A 
i
​
 .

If he is subject to a rating update in the 
i-th ARC, let 
T be his rating at the start of that contest. Then, after the contest, his rating becomes 
T+A 
i
​
 .

If his is not subject to a rating update, his rating does not change.

Rating updates for ARCs are performed immediately after the contest ends, and whether he is subject to rating updates in the next contest is determined based on his rating after the update.

Find his rating after finishing the 
N ARCs.

He does not participate in any contests other than these 
N ARCs, and his rating does not change in other ways
*/
void pre_pro(){
}
void dxt(int test_case){
    int n,r;
    cin >> n >> r;
    vector<pair<int,int>> ar(n);
    rep(i,0,n){
        cin >> ar[i].first >> ar[i].second;
    }
    int ans = r;
    rep(i,0,n){
        if(ar[i].first == 1){
            if(ans >= 1600 && ans <= 2799) ans += ar[i].second;
        }else{
            if(ans >= 1200 && ans <= 2399) ans += ar[i].second;
        }
    }
    cout << ans << endl;
}