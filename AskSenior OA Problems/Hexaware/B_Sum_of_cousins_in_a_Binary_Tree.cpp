/**
*    created: 2025-03-01 00:01:45
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
    cin >> T;
    for (int i = 1; i <= T; i++) {
        dxt(i);
    }
    return 0;
}

void pre_pro(){
}
void dxt(int test_case){
    int h;
    cin >> h;
    int n = (1 << (h + 1)) - 1;
    vector<int> tree(n);
    for (int i = 0; i < n; i++){
        cin >> tree[i];
    }
    if(tree[0] == -1){
        cout << -1 << "\n";
        return;
    }
    int k;
    cin >> k;
    int k_index = -1;
    for (int i = 0; i < n; i++){
        if(tree[i] == k) {
            k_index = i;
            break;
        }
    }
    if(k_index == -1){
        cout << -1 << "\n";
        return;
    }
    if(k_index == 0){
        cout << 0 << "\n";
        return;
    }
    int parent_index = (k_index - 1) / 2;
    int sibling_sum = 0;
    int left_child = 2 * parent_index + 1;
    int right_child = 2 * parent_index + 2;
    if(left_child < n && tree[left_child] != -1 && tree[left_child] != k)
        sibling_sum += tree[left_child];
    if(right_child < n && tree[right_child] != -1 && tree[right_child] != k)
        sibling_sum += tree[right_child];
    int target_level = floor(log2(k_index + 1));
    int level_sum = 0;
    int start = (1 << target_level) - 1;
    int end = (1 << (target_level + 1)) - 2;
    for (int i = start; i <= end && i < n; i++){
        if(tree[i] != -1)
            level_sum += tree[i];
    }
    int cousins_sum = level_sum - (k + sibling_sum);
    cout << cousins_sum << "\n";

}