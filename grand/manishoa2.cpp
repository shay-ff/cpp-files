/**
*    created: 2025-03-22 22:28:22
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

int Min_budget(int N, vector<int> arr){
    sort(arr.begin(), arr.end());

    // 2. We'll keep track of chosen base elements
    vector<long long> chosen;

    // 3. Maintain a set of reachable sums (start with 0)
    //    Using unordered_set<long long> for faster insert/find on average.
    unordered_set<long long> reachable;
    reachable.insert(0);

    // The largest value in arr; helps us limit expansions
    long long maxVal = arr.back();

    // 4. Check each element in ascending order
    for (long long val : arr) {
        // If val is not yet reachable, we need to buy/add it as a new base
        if (reachable.find(val) == reachable.end()) {
            chosen.push_back(val);

            // BFS/queue to expand new sums that include 'val' + any previously reachable sums
            queue<long long> q;
            q.push(val);

            while (!q.empty()) {
                long long cur = q.front();
                q.pop();

                // If we haven't already marked 'cur' as reachable, do so
                if (!reachable.count(cur)) {
                    reachable.insert(cur);

                    // Try adding each chosen base to 'cur'
                    for (long long c : chosen) {
                        long long nxt = cur + c;
                        // Only expand if it does not exceed the largest needed
                        if (nxt <= maxVal && !reachable.count(nxt)) {
                            q.push(nxt);
                        }
                    }
                }
            }
        }
    }

    // 5. The answer is the number of chosen base elements
    int ans = chosen.size();
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        cout << Min_budget(n, arr) << '\n';
    };
    int T = 1;
    // cin >> T    ;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}