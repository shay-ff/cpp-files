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
	int n,d,l;
	cin >> n >> d >> l;
	
	// Step 1: Validate input constraints
    if (d < 2 || d > n - 1 || l < 2 || l > n) {
        cout << "-1\n";
        return;
    }

    // Step 2: Calculate feasibility
    int minLeaves = 2;             // Minimum leaves (endpoints of the diameter path)
    int maxLeaves = n - (d - 1);   // Max leaves (all nodes except internal diameter nodes)

    if (l < minLeaves || l > maxLeaves) {
        cout << "-1\n";
        return;
    }

    // Step 3: Construct the diameter path
    vector<pair<int, int>> edges;
    for (int i = 1; i <= d; ++i) {
        edges.push_back({i, i + 1});
    }

    // Step 4: Add remaining nodes to form leaves
    int remainingNodes = n - (d + 1);  // Nodes not in the diameter path
    int leafCount = 2;                // Endpoints of the diameter are leaves

    // Attach remaining nodes as leaves to the diameter path
    for (int i = 1; i <= d && remainingNodes > 0; ++i) {
        while (leafCount < l && remainingNodes > 0) {
            edges.push_back({i, d + 1 + remainingNodes});
            --remainingNodes;
            ++leafCount;
        }
    }

    // If we fail to match the required number of leaves, output -1
    if (leafCount != l) {
        cout << "-1\n";
        return;
    }

    // Step 5: Output the edges
    for (auto [u, v] : edges) {
        cout << u << " " << v << "\n";
    }
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
	    dxt(i);
	}
	return 0;
}




/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 
*/
