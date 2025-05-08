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

void pre_pro(){
}
/*
There are times you recall a good old friend and everything you've come through together. Luckily there are social networks — they store all your message history making it easy to know what you argued over 10 years ago.

More formal, your message history is a sequence of messages ordered by time sent numbered from 1 to n where n is the total number of messages in the chat.

Each message might contain a link to an earlier message which it is a reply to. When opening a message x or getting a link to it, the dialogue is shown in such a way that k previous messages, message x and k next messages are visible (with respect to message x). In case there are less than k messages somewhere, they are yet all shown.

Digging deep into your message history, you always read all visible messages and then go by the link in the current message x (if there is one) and continue reading in the same manner.

Determine the number of messages you'll read if your start from message number t for all t from 1 to n. Calculate these numbers independently. If you start with message x, the initial configuration is x itself, k previous and k next messages. Messages read multiple times are considered as one.
*/
void dxt(int test_case){
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> ans(n);
    rep(i, 0, n){
        int x = i;
        int cnt = 1;
        while(a[x] != 0){
            x = a[x] - 1;
            cnt++;
        }
        ans[i] = cnt;
    }
    rep(i, 0, n) cout << ans[i] << " ";
}