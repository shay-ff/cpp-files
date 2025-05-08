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
Monocarp is preparing for his first exam at the university. There are 𝑛
 different questions which can be asked during the exam, numbered from 1
 to 𝑛
. There are 𝑚
 different lists of questions; each list consists of exactly 𝑛−1
 different questions. Each list 𝑖
 is characterized by one integer 𝑎𝑖
, which is the index of the only question which is not present in the 𝑖
-th list. For example, if 𝑛=4
 and 𝑎𝑖=3
, the 𝑖
-th list contains questions [1,2,4]
.

During the exam, Monocarp will receive one of these 𝑚
 lists of questions. Then, the professor will make Monocarp answer all questions from the list. So, Monocarp will pass only if he knows all questions from the list.

Monocarp knows the answers for 𝑘
 questions 𝑞1,𝑞2,…,𝑞𝑘
. For each list, determine if Monocarp will pass the exam if he receives that list.
*/
void pre_pro(){
}
void dxt(int test_case){
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];
    vector<int> q(k);
    for(int i = 0; i < k; i++) cin >> q[i];

    set<int> s(all(q));
    vector<int> ans(m, 0);
    
    for(int i = 0; i < m; ++i){
        int temp = a[i];
        int ok = 0;
        if(s.count(temp)){
            ok = 1;
            s.erase(temp);
        }
        if(sz(s) == n - 1) ans[i] = 1;
        if(ok) s.insert(temp);
    }
    rep(i,0,m) cout << ans[i];
    cout << endl;

}
