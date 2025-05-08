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

#define int long long int
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
You're given an array 
A
A of length 
N
N.
Every second, the following process will happen:

For each 
i
i from 
1
1 to 
N
−
1
N−1 in order, if 
A
i
<
A
i
+
1
A 
i
​
 <A 
i+1
​
 , set 
A
i
A 
i
​
  to 
A
i
+
1
A 
i+1
​
 .
For example, if 
A
=
[
3
,
1
,
4
,
1
,
5
]
A=[3,1,4,1,5], the process is as follows:

A
1
A 
1
​
  is not less than 
A
2
A 
2
​
 , so it won't change.
A
2
A 
2
​
  is less than 
A
3
A 
3
​
 , so 
A
2
A 
2
​
  will be set to 
A
3
=
4
A 
3
​
 =4.
A
3
A 
3
​
  is not less than 
A
4
A 
4
​
 , so it won't change.
A
4
A 
4
​
  is less than 
A
5
A 
5
​
 , so it will be set to 
A
5
=
5
A 
5
​
 =5.
The array after the changes is 
[
3
,
4
,
4
,
5
,
5
]
[3,4,4,5,5].

A
A is said to be stable if none of its elements change after the process.
How many seconds will it take for 
A
A to become stable?
*/
void pre_pro(){
}
void dxt(int test_case){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<pair<int,int>> br;
    for(int i = 0; i < n; ++i){
        br.push_back({a[i], i});
    }
    int ans = 0;
    sort(allr(br));
    for(int i = 0; i < n; ++i){
        ans = max(ans, br[i].second - i);
    }
    show(ans);
}