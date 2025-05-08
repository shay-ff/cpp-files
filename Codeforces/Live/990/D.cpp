#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
set<pair<int,int>> vis;
vector<array<int,3>> points;
map<pair<int,int>,vector<pair<int,int>>> adj;
void dfs(pair<int,int> &b, int &ans){
  vis.insert(b);
  ans++;
  for(auto &pa : adj[b]){
    if(!vis.count(pa)){
      dfs(pa, ans);
    }
  }
}
  int main() {
    int n;
    cin >> n;
    vis.clear();
    points.clear();
    points.resize(n);
    adj.clear();
    
    for(int i = 0; i < n; ++i){
      int x,y,r;
      cin >> x >> y >> r;
      points[i] = {x,y,r};
    }
    auto dist = [&](array<int,3> &a, array<int,3> &b){
      long long int d = sqrtl((b[0] - a[0])*1LL*(b[0] - a[0]) + 
        (b[1] - a[1])*1LL*(b[1]-a[1]));
      return d;
    };
    
    debug(points);
    
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        int d = dist(points[i], points[j]);
	      if(d <= points[i][2]){
	        adj[{points[i][0], points[i][1]}].push_back({points[j][0], points[j][1]});
	      }
      }
    }
    // for(auto &pa : adj){
    // 	cout << pa.first.first << " " << pa.first.second << " |";
    // 	// auto it = pa.second.find(pa.first);
    // 	// pa.second.erase(it);
    // 	for(auto &x : pa.second){
    // 		cout << x.first << " " << x.second << ", ";
    // 	}
    // 	cout << endl;
    // }
    int cntr = 0;
    for(int i = 0; i < n; ++i){
      int ans = 0;
      int u = points[i][0], v = points[i][1];
      pair<int,int> curr = {u,v};
      if(!vis.count(curr)){
        dfs(curr, ans);
        debug(curr, ans, vis);
        cntr = max(cntr, ans);
      }
    }
    cout << cntr << endl;

    return 0;

  }