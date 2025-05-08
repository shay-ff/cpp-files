#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
 
// Fast I/O
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
int main(){
    fastIO();
    int T;
    cin >> T;
    
    while(T--){
        int n;
        cin >> n;
        vector<vector<int>> g(n, vector<int>(n));
        int mxv = 0;
    
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                cin >> g[i][j];
                mxv = max(mxv, g[i][j]);
            }
        }
        vector<vector<int>> rows(n, vector<int>(n)), pref(n, vector<int>(n + 1, 0));
        row = g;
        set<int> st;
        st.insert(1);
        for (int i = 0; i < n; ++i) {
            sort(rows[i].begin(), rows[i].end());
            for (int j = 0; j < n; ++j) {
                pref[i][j+1] = pref[i][j] + rows[i][j];
                st.insert(rows[i][j]);
                st.insert(rows[i][j] + 1);
            }
        }
        st.insert(mxv);

        vector<int> pos(n, 0);
     
        int ans = 0, res = -1;
    
        for (int x : st) {
            for (int i = 0; i < n; ++i) {
                while (pos[i] < n && rows[i][pos[i]] <= x) {
                    pos[i]++;
                }
            }
     
            int f1 = pref[0][pos[0]] + x * (n - pos[0]);
            int sc = 0;
            for (int i = 1; i < n; ++i) {
                int fi = pref[i][pos[i]] + x * (n - pointers[i]);
                if (fi > f1) {
                    sc++;
                }
            }
     
            if (sc > res) {
                res = sc;
                ans = x;
            }
        }
     
        cout << ans << "\n";
    }
    return 0;
}
