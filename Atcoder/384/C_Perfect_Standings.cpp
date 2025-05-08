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
Takahashi decided to hold a programming contest.

The contest consists of five problems: A, B, C, D, E, with scores 
a, 
b, 
c, 
d, 
e, respectively.

There are 
31 participants, and all of them solved at least one problem.

More specifically, for every non-empty subsequence (not necessarily contiguous) of the string ABCDE, there is a participant named after that subsequence who solved the problems corresponding to the letters in their name and did not solve the other problems.

For example, participant A solved only problem A, and participant BCE solved problems B, C, and E.

Print the names of the participants in order of their obtained scores, from the largest to the smallest. The score obtained by a participant is the sum of the scores of the problems they solved.

If two participants obtained the same score, print the one whose name is lexicographically smaller first.
*/
void pre_pro(){
}
void dxt(int test_case){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    vector<pair<int, string>> v;
    string s = "ABCDE";

    for(int i = 0; i < (1LL << 5); i++){
        string t = "";
        int sum = 0;
        for(int j = 0; j < 5; j++){
            if(i & (1LL << j)){
                t += s[j];
                sum += (j == 0 ? a : j == 1 ? b : j == 2 ? c : j == 3 ? d : e);
            }
        }
        if(t.size() == 0) continue;
        v.push_back({sum, t});
    }
    auto cmp = [&](pair<int, string> &x, pair<int, string> &y){
        if(x.first == y.first) return x.second < y.second;
        return x.first > y.first;
    };
    sort(all(v), cmp);

    // reverse(all(v));
    for(auto &x : v){
        cout << x.second << endl;
    }

}