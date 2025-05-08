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
H rows and 
W columns. Let 
(i,j) denote the cell at the 
i-th row from the top and the 
j-th column from the left.

If 
S 
i,j
​
  is #, the cell 
(i,j) is impassable; if it is ., the cell is passable and contains no house; if it is @, the cell is passable and contains a house.

Initially, Santa Claus is in cell 
(X,Y). He will act according to the string 
T as follows.

Let 
∣T∣ be the length of the string 
T. For 
i=1,2,…,∣T∣, he moves as follows.
Let 
(x,y) be the cell he is currently in.
If 
T 
i
​
  is U and cell 
(x−1,y) is passable, move to cell 
(x−1,y).
If 
T 
i
​
  is D and cell 
(x+1,y) is passable, move to cell 
(x+1,y).
If 
T 
i
​
  is L and cell 
(x,y−1) is passable, move to cell 
(x,y−1).
If 
T 
i
​
  is R and cell 
(x,y+1) is passable, move to cell 
(x,y+1).
Otherwise, stay in cell 
(x,y).
Find the cell where he is after completing all actions, and the number of distinct houses that he passed through or arrived at during his actions. If the same house is passed multiple times, it is only counted once.

*/
void pre_pro(){
}
void dxt(int test_case){
    int h,w,x,y;
    cin >> h >> w >> x >> y;
    x--; y--;
    vector<string> grid(h);
    rep(i,0,h) cin >> grid[i];
    string t;
    cin >> t;
    int ans = 0;
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    rep(i,0,sz(t)){
        if(t[i] == 'U' && x > 0 && grid[x - 1][y] != '#') x--;
        if(t[i] == 'D' && x < h - 1 && grid[x + 1][y] != '#') x++;
        if(t[i] == 'L' && y > 0 && grid[x][y - 1] != '#') y--;
        if(t[i] == 'R' && y < w - 1 && grid[x][y + 1] != '#') y++;
        if(grid[x][y] == '@' && !vis[x][y]){
            ans++;
            vis[x][y] = true;
        }
    }
    show(x + 1 << " " << y + 1 << " " << ans);

}