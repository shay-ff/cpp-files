/**
*    created: 2025-04-24 20:26:30
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto solve_test = [&](int test_case) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);

        for(int i = 0; i < n; i++) 
            cin >> a[i];
    
        for(int i = 0; i < m; i++)
            cin >> b[i];
        
        auto can = [&](int cap){
            int left = 0, used = 0;
            for(int i = 0; i < n; i++) {
                if(used < m && a[i] >= b[used]) {
                    used++;
                }
                if(left < m && cap >= b[left]) {
                    int temp = left + 1;
                    if(temp < m && a[i] >= b[temp]) {
                        temp++;
                    }
                    used = max(used, temp);
                }
                if(left < m && a[i] >= b[left]) {
                    left++;
                }
            }
            if(left < m && cap >= b[left]) {
                used = max(used, left + 1);
            }
            return (used == m);
        };

        const int INF = 2e18;
        if(can(-INF)){
            show(0);
            return;
        }
        if(!can(INF)){
            show(-1);
            return;
        }
        vector<int> st(b.begin(), b.end());
        sort(st.begin(), st.end());
        st.resize(unique(st.begin(), st.end()) - st.begin());

        int low = 0, high = st.size() - 1;
        int ans = high;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(can(st[mid])) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        show(st[low]);

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        solve_test(i);
    }
}