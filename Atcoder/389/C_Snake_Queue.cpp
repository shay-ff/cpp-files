/**
*    created: 2025-01-18 17:32:54
**/
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

// order_of_key (k) : Number of items strictly smaller than k.
// find_by_order(k) : K-th element in a set (counting from zero).
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009, 1000000023, 1000000007, 998244353

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
There is a queue of snakes. Initially, the queue is empty.

You are given 
Q queries, which should be processed in the order they are given. There are three types of queries:

Type 
1: Given in the form 1 l. A snake of length 
l is added to the end of the queue. If the queue was empty before adding, the head position of the newly added snake is 
0; otherwise, it is the sum of the head coordinate of the last snake in the queue and the last snake’s length.
Type 
2: Given in the form 2. The snake at the front of the queue leaves the queue. It is guaranteed that the queue is not empty at this time. Let 
m be the length of the snake that left, then the head coordinate of every snake remaining in the queue decreases by 
m.
Type 
3: Given in the form 3 k. Output the head coordinate of the snake that is 
k-th from the front of the queue. It is guaranteed that there are at least 
k snakes in the queue at this time.
*/
void pre_pro(){
}
// 
void dxt(int test_case) {
    int q;
    cin >> q;
    deque<pair<int, int>> dq; 
    int rem = 0, next = 0;  
    
    for(int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int l;
            cin >> l;
            dq.push_back({next, l});
            next = next + l;
        }
        else if(type == 2) {
            rem += dq.front().second;
            dq.pop_front();
        }
        else {
            int k; cin >> k; --k;
            cout << dq[k].first - rem << endl;
        }
    }
}