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
const int N = 200200, INF = 1e8, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

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
You are given a rectangular field of n × m cells. Each cell is either empty or impassable (contains an obstacle). 
Empty cells are marked with '.', impassable cells are marked with '*'. Let's call two empty cells adjacent if they share a side.
Let's call a connected component any non-extendible set of cells such that any two of them are 
connected by the path of adjacent cells. It is a typical well-known definition of a connected component.
For each impassable cell (x, y) imagine that it is an empty cell (all other cells remain unchanged)
 and find the size (the number of cells) of the connected component which contains (x, y). You should do it for each impassable cell independently.
The answer should be printed as a matrix with n rows and m columns. The j-th symbol of the i-th row should be
 "." if the cell is empty at the start. Otherwise the j-th symbol of the i-th row should contain the only digit —- the answer modulo 10. The matrix should be printed without any spaces.
*/
void pre_pro(){
}
class DSU
{
public:
    vector<int> parent;
    vector<int> sizes;
    DSU(int n)
    {
        parent.resize(n);
        sizes.resize(n);
        for (int i = 0; i < n; i++)
            make_set(i);
    }
    void make_set(int v)
    {
        parent[v] = v;
        sizes[v] = 1;
    }
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
 
    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (sizes[a] < sizes[b])
                swap(a, b);
            parent[b] = a;
            sizes[a] += sizes[b];
        }
    }
};

void dxt(int test_case) {
   int n,m; cin >> n >> m;
    vector<string> ar(n);
    for(int i = 0; i < n; ++i){
        cin >> ar[i];
    }
    DSU dsu(n * m);
    int dir[] = {-1, 0, 1, 0, -1};

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(ar[i][j] == '.'){
                for(int k = 0; k < 4; ++k){
                    int x = i + dir[k], y = j + dir[k + 1];
                    if(x >= 0 && x < n && y >= 0 && y < m && ar[x][y] == '.'){
                        dsu.union_sets(x * m + y, i * m + j);
                    }
                }
            }
        }
    }

    rep(i,0 , n){
        rep(j, 0 , m){
            if(ar[i][j] == '*'){
                map<int,int> cnt;
                for(int k = 0; k < 4; ++k){
                    int x = i + dir[k], y = j + dir[k + 1];
                    if(x >= 0 && x < n && y >= 0 && y < m && ar[x][y] == '.'){
                        int t = dsu.find_set(x * m + y);
                        cnt[t]++;
                    }
                }
                int sum = 1;
                for(auto &x : cnt) sum += dsu.sizes[x.first];
                cout << sum % 10;
            }
            else cout << ".";
        }
        cout << endl;
    }
   
    
}