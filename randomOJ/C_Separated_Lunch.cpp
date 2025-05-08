/*
As KEYENCE headquarters have more and more workers, they decided to divide the departments in the headquarters into two groups and stagger their lunch breaks.

KEYENCE headquarters have 
N departments, and the number of people in the 
i-th department 
(1≤i≤N) is 
K 
i
​
 .

When assigning each department to Group 
A or Group 
B, having each group take lunch breaks at the same time, and ensuring that the lunch break times of Group 
A and Group 
B do not overlap, find the minimum possible value of the maximum number of people taking a lunch break at the same time.
In other words, find the minimum possible value of the larger of the following: the total number of people in departments assigned to Group 
A, and the total number of people in departments assigned to Group 
B.

*/

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void dxt(int test_case){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    vector<int> pref(n);
    pref[0] = a[0];
    for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];
    int ans = 1e18;
    for(int i = 0; i < n; i++){
        int x = pref[i];
        int y = pref[n - 1] - pref[i];
        ans = min(ans, max(x, y));
    }
    cout << ans << '\n';
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