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
/*
There is a printing machine that prints line segments on the 
xy-plane by emitting a laser.

At the start of printing, the laser position is at coordinate 
(0,0).
When printing a line segment, the procedure below is followed.

First, move the laser position to one of the endpoints of the line segment.
One may start drawing from either endpoint.
Then, move the laser position in a straight line from the current endpoint to the other endpoint while emitting the laser.
It is not allowed to stop printing in the middle of a line segment.
When not emitting the laser, the laser position can move in any direction at a speed of 
S units per second.

When emitting the laser, the laser position can move along the line segment being printed at a speed of 
T units per second.
The time required for operations other than moving the laser position can be ignored.
Takahashi wants to print 
N line segments using this printing machine.
The 
i-th line segment connects coordinates 
(Ai,Bi) and 
(Ci,D i).
Some line segments may overlap, in which case he needs to print the overlapping parts for each line segment separately.

What is the minimum number of seconds required to complete printing all the line segments when he operates the printing machine optimally?
*/
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

void pre_pro(){
}
struct Point {
    double x, y;
};
void dxt(int test_case){
    int n,s,t;
    cin >> n >> s >> t;
    double ans = 1e18;
    for(int i = 0; i < n; i++){
        Point a,b;
        cin >> a.x >> a.y >> b.x >> b.y;
        double d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
        ans = min(d * s, d * t);
    }
    cout << ans << '\n';
}















/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 

*/







