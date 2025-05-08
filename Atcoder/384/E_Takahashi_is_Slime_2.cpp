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
There is a grid with 
H horizontal rows and 
W vertical columns. Let 
(i,j) denote the cell at the 
i-th row 
(1≤i≤H) from the top and 
j-th column 
(1≤j≤W) from the left.

Initially, there is a slime with strength 
S 
i,j
​
  in cell 
(i,j), and Takahashi is the slime in the cell 
(P,Q).

Find the maximum possible strength of Takahashi after performing the following action any number of times (possibly zero):

Among the slimes adjacent to him, choose one whose strength is strictly less than 
X
1
​
  times his strength and absorb it. As a result, the absorbed slime disappears, and Takahashi's strength increases by the strength of the absorbed slime.
When performing the above action, the gap left by the disappeared slime is immediately filled by Takahashi, and the slimes that were adjacent to the disappeared one (if any) become newly adjacent to Takahashi (refer to the explanation in sample 1).
*/
void pre_pro(){
}
void dxt(int test_case){
    int h,w,p,q,x;
    cin >> h >> w >> x >> p >> q;
    // debug(h, w, p, q, x);
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
    
    int str = a[p-1][q-1];
    a[p-1][q-1] = -1;
    // create a min heap
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    int dx[] = {-1, 0, 1, 0, -1};

    auto valid = [&](int i, int j){
        return (i >= 0 && i < h && j >= 0 && j < w);
    };
    --p, --q;
    for(int i = 0; i < 4; ++i){
        int xx = p + dx[i];
        int yy = q + dx[i+1];
        if(valid(xx, yy) && a[xx][yy] != -1){
            pq.push({a[xx][yy], xx, yy});
        }
    }
    
    while(!pq.empty()){
        auto [s, i, j] = pq.top();
        pq.pop();
        if(s > str/x) break;
        if(s * x < str){
            str += s;
            a[i][j] = -1;
            for(int k = 0; k < 4; ++k){
                int xx = i + dx[k];
                int yy = j + dx[k+1];
                if(valid(xx, yy) && a[xx][yy] != -1){
                    pq.push({a[xx][yy], xx, yy});
                }
            }
        }
        else break;
    }
    show(str);
}