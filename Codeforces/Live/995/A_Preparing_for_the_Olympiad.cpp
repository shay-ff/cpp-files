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
Monocarp and Stereocarp are preparing for the Olympiad. There are 𝑛
 days left until the Olympiad. On the 𝑖
-th day, if Monocarp plans to practice, he will solve 𝑎𝑖
 problems. Similarly, if Stereocarp plans to practice on the same day, he will solve 𝑏𝑖
 problems.

Monocarp can train on any day he wants. However, Stereocarp watches Monocarp and follows a different schedule: if Monocarp trained on day 𝑖
 and 𝑖<𝑛
, then Stereocarp will train on day (𝑖+1)
.

Monocarp wants to organize his training process in a way that the difference between the number of problems he solves and the number of problems Stereocarp solves is as large as possible. Formally, Monocarp wants to maximize the value of (𝑚−𝑠)
, where 𝑚
 is the number of problems he solves, and 𝑠
 is the number of problems Stereocarp solves. Help Monocarp determine the maximum possible difference in the number of solved problems between them.
*/

void pre_pro(){
}
void dxt(int test_case){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int prev = 0, curr = 0;

    for (int i = 1; i <= n; i++) {
        curr = max(prev, prev + a[i - 1] - (i < n ? b[i] : 0));
        prev = curr;
    }

    cout << curr << endl;


}