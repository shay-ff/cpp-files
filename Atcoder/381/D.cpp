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
	int n;
    cin >> n;
    vector<int> a(n);
    
    // Read input and find max value
    int maxVal = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }
    
    // Use array for O(1) access to last positions
    vector<int> lastFirst(maxVal + 1, -1);
    int maxLen = 0;
    int left = 0;
    
    for(int right = 0; right < n; right++) {
        int curr = a[right];
        
        if(lastFirst[curr] != -1) {
            int firstPos = lastFirst[curr];
            
            // If not forming a consecutive pair
            if(firstPos != right - 1) {
                // Move left pointer and clear old entries
                int newLeft = firstPos + 1;
                for(int i = left; i < newLeft; i++) {
                    if(lastFirst[a[i]] < newLeft) {
                        lastFirst[a[i]] = -1;
                    }
                }
                left = newLeft;
            } else {
                // Valid pair found - check if window is valid
                if((right - left + 1) % 2 == 0) {
                    maxLen = max(maxLen, right - left + 1);
                }
                lastFirst[curr] = -1;  // Reset after forming pair
            }
        } else {
            lastFirst[curr] = right;
        }
    }
    cout << maxLen << endl;
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




/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 
*/
