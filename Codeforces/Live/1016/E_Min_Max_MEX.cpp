/**
*    created: 2025-04-08 20:43:59
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

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        vector<int> freq(n + 1, 0);
        auto can = [&](int mid) {
            int seg = 0, req = mid;  
            int unique_count = 0; 
            for (int i = 0; i < n; ++i) {
            if (a[i] < n + 1) {  
                if (freq[a[i]] == 0) {
                unique_count++;
                }
                freq[a[i]]++;
                req--; 
            }
            if (req == 0) {
                seg++;
                if (seg == k) {
                return true;
                }
                req = mid;
                for (int j = 0; j < n + 2; ++j) {
                    if (freq[j] > 0) {
                        freq[j] = 0;
                    }
                }
                unique_count = 0;
            }
            }
            return false;
        };
        int low = 0, high = n, ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(can(mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout << ans << endl;
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}