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
Takahashi is going to read a manga series "Snuke-kun" in 
10 
9
  volumes.
Initially, Takahashi has 
N books of this series. The 
i-th book is Volume 
a 
i
​
 .

Takahashi may repeat the following operation any number of (possibly zero) times only before he begins to read:

Do nothing if he has 
1 or less books; otherwise, sell two of the books he has and buy one book of any volume instead.
Then, Takahashi reads Volume 
1, Volume 
2, Volume 
3, 
…, in order. However, when he does not have a book of the next volume to read, he stops reading the series (regardless of the other volumes he has).

Find the latest volume of the series that he can read up to. If he cannot read any, let the answer be 
0.
*/

void pre_pro(){
}
void dxt(int test_case){
    int n;
    cin >> n;

    vector<int> ar(n);
    for(auto &i : ar) cin >> i;
    if(n < 2){
        cout << (ar[0] == 1 ? 1 : 0) << endl;
        return;
    }
    vector<int> have(n + 2, 0);
    int ext = 0;
    for(int i = 0; i < n; ++i){
        if(ar[i] >= n) ext++;
        else if(have[ar[i]]) ext++;
        else have[ar[i]] = 1;
    }
    int can = 0, l = 1, r = n + 1;;
    while(true){
        while(have[l]) ++l;
        while(r != 0 && !have[r]) --r; 
        if(ext >= 2){
            ext -= 2;
            have[l] = 1;
        } else{
            if(l >= r) 
                break;
            have[r] = 0;
            ext++;
        }
    }
    l-= 1;
    show(l);
}