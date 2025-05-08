#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

void dxt(int test_case){
	int h,w, k;
	cin >> h >> w >> k;

	vector<vector<char>> gr(h,vector<char> (w));
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			cin >> gr[i][j];
		}
	}
	vector<vector<bool>> vis(h, vector<bool>(w, false));
    queue<pair<int, pair<int, int>>> q; 

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (gr[i][j] == 'H') {
                q.push({0, {i, j}});
                vis[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        int dist = q.front().first;
        int r = q.front().second.first, c = q.front().second.second;
        q.pop();

        if (dist == k) continue; 

        for (int i = 0; i < 4; ++i) {
            int xx = r + dx[i], yy = c + dx[i + 1];
            if (xx >= 0 && xx < h && yy >= 0 && yy < w && !vis[xx][yy] && gr[xx][yy] != '#') {
                vis[xx][yy] = true;
                q.push({dist + 1, {xx, yy}});
            }
        }
    }

   
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (vis[i][j] && (gr[i][j] == '.' || gr[i][j] == 'H')) {
                ans++;
            }
        }
    }
    cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	// cin >> T;
	for (int i = 1; i <= T; i++) {
	    dxt(i);
	}
	return 0;
}




