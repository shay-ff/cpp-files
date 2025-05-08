#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> good;
vector<vector<bool>> visited;  // To mark visited cells
int n, m;

void cnt(int x, int y, int &c) {
    if (x >= n || x < 0 || y >= m || y < 0 || !good[x][y] || visited[x][y]) {
        return;
    }
    visited[x][y] = true;  // Mark the cell as visited
    c++;  // Increment the count
    // Explore in all 8 directions
    cnt(x + 1, y, c);
    cnt(x - 1, y, c);
    cnt(x, y + 1, c);
    cnt(x, y - 1, c);
    cnt(x - 1, y - 1, c);
    cnt(x + 1, y - 1, c);
    cnt(x - 1, y + 1, c);
    cnt(x + 1, y + 1, c);
}

bool dfs(int x, int y) {
    int _cnt = 0;
    cnt(x, y, _cnt);
    if(_cnt == 3){
    	
    }
    return (_cnt == 3);  // Check if the count is exactly 3
}

void dxt() {
    cin >> n >> m;
    good.resize(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));  
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x;
            cin >> x;
            good[i][j] = (x == '.' ? 0 : 1);
        }
    }

    bool ans = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (good[i][j] && !visited[i][j]) {
                ans &= dfs(i, j);
            }
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        dxt();
    }

    return 0;
}
