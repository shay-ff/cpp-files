/**
*    created: 2025-02-25 21:11:39
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
void dxt(int test_case) {
    int n, x;
    cin >> n >> x;
    
    if (x == 0) {
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }
    
    // Try to maximize MEX by including [0,1,...,mex-1]
    int max_mex = 0;
    vector<int> best_ans;
    
    for (int mex = 0; mex <= min(n, 31LL); mex++) {  // Limit to 31 bits
        vector<int> candidate;
        int current_or = 0;
        
        // Fill with [0,1,...,mex-1]
        for (int i = 0; i < mex; i++) {
            candidate.push_back(i);
            current_or |= i;
        }
        
        // Check if any bits in current_or are not in x
        if ((current_or & ~x) != 0) {
            // Not possible to have this MEX
            continue;
        }
        
        // Calculate what's needed to make OR = x
        int needed = x & ~current_or;
        
        // If needed is already in our array, we need to adjust
        bool conflict = false;
        for (int i = 0; i < mex; i++) {
            if (candidate[i] == needed) {
                conflict = true;
                break;
            }
        }
        
        // If needed conflicts with an existing element, 
        // we need to remove that element and try a different approach
        if (conflict) {
            continue;
        }
        
        // If we can add 'needed', do so
        if (candidate.size() < n) {
            candidate.push_back(needed);
        } else {
            // We've used all n slots but still need to add 'needed'
            continue;
        }
        
        // Fill remaining slots with zeros
        while (candidate.size() < n) {
            candidate.push_back(0);
        }
        
        // Verify OR = x
        int check_or = 0;
        for (int val : candidate) {
            check_or |= val;
        }
        
        if (check_or == x && mex > max_mex) {
            max_mex = mex;
            best_ans = candidate;
        }
    }
    
    // Special case handling
    if (best_ans.empty()) {
        // Fallback solution: [0, x, 0, 0, ...]
        best_ans.push_back(0);
        best_ans.push_back(x);
        while (best_ans.size() < n) {
            best_ans.push_back(0);
        }
    }
    
    // Output
    for (auto& i : best_ans) {
        cout << i << " ";
    }
    cout << endl;
}