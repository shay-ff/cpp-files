#include<bits/stdc++.h>
using namespace std;
#define int long long int
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007;

void solve(int test_case) {
    int h, w, d;
    cin >> h >> w >> d;
    vector<string> grid(h);
    vector<pair<int, int>> fc;
    
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
        for (int j = 0; j < w; ++j) { 
            if (grid[i][j] == '.') {
                fc.push_back({i, j});
            }
        }
    }
    
    int mxh = 0;
    
    for (int i = 0; i < (int)fc.size(); ++i) {
        for (int j = i + 1; j < (int)fc.size(); j++) {
            set<pair<int, int>> done;
            
            done.insert(fc[i]);
            done.insert(fc[j]);
         
            for (auto& cell : fc) {
                int d1 = abs(cell.first - fc[i].first) + 
                            abs(cell.second - fc[i].second);
                int d2 = abs(cell.first - fc[j].first) + 
                            abs(cell.second - fc[j].second);
                
                if (d1 <= d || d2 <= d) {
                    done.insert(cell);
                }
            }
            
            mxh = max(mxh, (int)done.size());
        }
    }
    
    cout << mxh << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int T = 1;
    // cin >> T;    
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    
    return 0;
}

/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 
*/