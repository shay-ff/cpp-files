/**
*    created: 2025-03-12 14:13:58
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
        int n,m;
        cin >> n >> m;
        vector<int> r(n), x(n);
        for(int i = 0; i < n; ++i){
            cin >> x[i];
        }
        for(int i = 0; i < n; ++i){
            cin >> r[i];
        }
        int maxR = 0;
        for(int i = 0; i < n; ++i){
            if(r[i] > maxR) maxR = r[i];
        }
        vector<vector<pair<int, int>>> intervals(maxR + 1);
        for(int i = 0; i < n; ++i){
            int rr = r[i];
            int xx = x[i];
            for(int y = 0; y <= rr; ++y){
                int diff = rr*rr - y*y;
                int d = (int)floor(sqrt((long double)diff));
                int L = xx - d;
                int R = xx + d;
                intervals[y].push_back({L, R});
            }
        }
        int answer = 0;
        for(int y = 0; y <= maxR; ++y){
            if(intervals[y].empty()) continue;
            sort(intervals[y].begin(), intervals[y].end(), [&](const pair<int, int> &a, const pair<int, int> &b){
                return a.first < b.first;
            });
            int mergedCount = 0;
            pair<int, int> cur = intervals[y][0];
            for(int j = 1; j < sz(intervals[y]); ++j){
                pair<int, int> &next = intervals[y][j];
                if(next.first <= cur.second + 1){
                    if(next.second > cur.second){
                        cur.second = next.second;
                    }
                }else{
                    mergedCount += (cur.second - cur.first + 1);
                    cur = next;
                }
            }
            mergedCount += (cur.second - cur.first + 1);
            if(y == 0) answer += mergedCount;
            else answer += 2*mergedCount;
        }
        show(answer);
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}