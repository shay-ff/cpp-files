/**
*    created: 2025-03-23 05:16:37
**/
#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())
struct SegmentTree {
        int n;
        vector<int> tree_max, tree_min, tree_sum, lazy;

        SegmentTree(int size) {
            n = size;
            tree_max.resize(4 * n);
            tree_min.resize(4 * n);
            tree_sum.resize(4 * n);
            lazy.resize(4 * n);
        }

        void build(vector<int>& a, int v, int tl, int tr) {
            if (tl == tr) {
                tree_max[v] = tree_min[v] = tree_sum[v] = a[tl];
            } else {
                int tm = (tl + tr) / 2;
                build(a, v * 2, tl, tm);
                build(a, v * 2 + 1, tm + 1, tr);
                tree_max[v] = max(tree_max[v * 2], tree_max[v * 2 + 1]);
                tree_min[v] = min(tree_min[v * 2], tree_min[v * 2 + 1]);
                tree_sum[v] = tree_sum[v * 2] + tree_sum[v * 2 + 1];
            }
        }

        void push(int v, int tl, int tr) {
            if (lazy[v] != 0) {
                int tm = (tl + tr) / 2;
                apply(v * 2, tl, tm, lazy[v]);
                apply(v * 2 + 1, tm + 1, tr, lazy[v]);
                lazy[v] = 0;
            }
        }

        void apply(int v, int tl, int tr, int addend) {
            tree_max[v] += addend;
            tree_min[v] += addend;
            tree_sum[v] += addend * (tr - tl + 1);
            lazy[v] += addend;
        }

        void update(int v, int tl, int tr, int l, int r, int addend) {
            if (l > r) return;
            if (l == tl && r == tr) {
                apply(v, tl, tr, addend);
            } else {
                push(v, tl, tr);
                int tm = (tl + tr) / 2;
                update(v * 2, tl, tm, l, min(r, tm), addend);
                update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
                tree_max[v] = max(tree_max[v * 2], tree_max[v * 2 + 1]);
                tree_min[v] = min(tree_min[v * 2], tree_min[v * 2 + 1]);
                tree_sum[v] = tree_sum[v * 2] + tree_sum[v * 2 + 1];
            }
        }

        int query_max(int v, int tl, int tr, int l, int r) {
            if (l > r) return LLONG_MIN;
            if (l <= tl && tr <= r) return tree_max[v];
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            return max(query_max(v * 2, tl, tm, l, min(r, tm)), query_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
        }

        int query_min(int v, int tl, int tr, int l, int r) {
            if (l > r) return LLONG_MAX;
            if (l <= tl && tr <= r) return tree_min[v];
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            return min(query_min(v * 2, tl, tm, l, min(r, tm)), query_min(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
        }

        int query_sum(int v, int tl, int tr, int l, int r) {
            if (l > r) return 0;
            if (l <= tl && tr <= r) return tree_sum[v];
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            return query_sum(v * 2, tl, tm, l, min(r, tm)) + query_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        }
    };

/*
You are working under the Hokage's Office as a surveyor, and your job is to answer the queries made by your supervisor,
 Shikamaru based on the information you have and the updates about the village you get. Assume there are 𝑛 buildings in 
 Konoha numbered 1, 2, 3, ..., 𝑛. You have been given the number of residents in each of the buildings initially. 
 Shikamaru is interested in getting the maximum, sum, and minimum number of the residents between a certain range.
 The residents of the village aren't immune to death, and can have children. So over time each house would
 have an increase or decrease in the number of residents. You will receive those updates as and when they 
 happen as it is important to have accurate data for the survey.
*/
// make a pow function here

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        vector<vector<int>> wexondrivas = queries;
        long long totalOperations = 0;
        
        for (auto &vec : queries) {
            int l = vec[0], r = vec[1];
            long long currSteps = 0;
            long long lowk = 1;
            int k = 1;
            
            while (lowk <= r) {
                long long highk;
                if (lowk > (LLONG_MAX / 4)) {
                    highk = r;
                } else {
                    highk = lowk * 4 - 1;
                }
                if (highk > r) highk = r;
                
                long long newl = max((long long)l, lowk);
                long long newr = min((long long)r, highk);
                
                if (newl <= newr) {
                    long long count = newr - newl + 1;
                    currSteps += count * k;
                }
                
                k++;
                if (lowk > r / 4) break;
                lowk *= 4;
            }
            
            totalOperations += (currSteps + 1) / 2LL;
        }
        
        return totalOperations;
    }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        SegmentTree segtree(n);
        segtree.build(a, 1, 0, n - 1);

        while(q--){
            int type;
            cin >> type;
            if(type == 1){
                int l, r;
                cin >> l >> r;
                l--, r--;
                int mx = segtree.query_max(1, 0, n - 1, l, r);
                int mn = segtree.query_min(1, 0, n - 1, l, r);
                int sum = segtree.query_sum(1, 0, n - 1, l, r);
                cout << mx << " " << sum << " " << mn << "\n";
            }
            else{
                int a, b;
                cin >> a >> b;
                a--;
                int current_value = segtree.query_sum(1, 0, n - 1, a, a);
                int addend = b - current_value;
                segtree.update(1, 0, n - 1, a, a, addend);
     
            }
        }
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}