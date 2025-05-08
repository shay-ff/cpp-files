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
const int maxm = 210;
char gr[maxm][maxm][4];
void pre_pro(){
}
void dxt(int test_case){
    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    for(auto &i : v) cin >> i;
    vector<vector<bool>> vis(n,vector<bool>(m,0)), been(n,vector<bool>(m,0));
    queue<pair<int,int>> q;
    q.push({1,1});
    vis[1][1] = true;
    been[1][1] = true;
    int dir[] = {-1, 0, 1, 0, -1};
    auto valid = [&](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        rep(i,0,4){
            int xx = x, yy = y;
            while(  valid(xx,yy) && v[xx][yy] != '#'){
                been[xx][yy] = true;
                xx += dir[i];
                yy += dir[i+1];
            }
            xx -= dir[i];
            yy -= dir[i+1];
            if(valid(xx,yy) && vis[xx][yy]){
                continue;
            }
            if(!valid(xx,yy)) continue;
            vis[xx][yy] = true;
            q.push({xx,yy});
        }

    }
    int ans = 0;
    rep(i,0,n){
        rep(j,0,m){
            if(been[i][j] && v[i][j] == '.') ans++;
        }
    }
    show(ans);

    
}