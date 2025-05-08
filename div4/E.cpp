#include <bits/stdc++.h>
using namespace std;
 
// We treat a '0' as +1 and a '1' as -1 in our simulation.
// Feasibility check for an "up" move (i.e. placing a '0')
bool feasibleUp(int cur, int ru, int rd, int U, int F) {
    if(ru <= 0) return false;
    int ncur = cur + 1;
    if(ncur > U) return false;
    // After using one up, remaining ups become ru-1, downs remain rd.
    int maxFinal = ncur + (ru - 1);
    int minFinal = ncur - rd;
    return (minFinal <= F && F <= maxFinal);
}
 
// Feasibility check for a "down" move (i.e. placing a '1')
bool feasibleDown(int cur, int ru, int rd, int L, int F) {
    if(rd <= 0) return false;
    int ncur = cur - 1;
    if(ncur < L) return false;
    int maxFinal = ncur + ru;
    int minFinal = ncur - (rd - 1);
    return (minFinal <= F && F <= maxFinal);
}
 
// Construct a valid string when F = n-m is nonnegative.
// Allowed range is [0, k]. We force the maximum by starting with k zeros.
string constructNonNegative(int F, int k, int n, int m) {
    // Must have n >= k and F <= k.
    if(n < k || F > k) return "";
    int total = n + m;
    string res; res.resize(total);
    int pos = 0;
    // Force k zeros.
    for (int i = 0; i < k; i++){
        res[pos++] = '0';
    }
    int cur = k;         // current prefix sum
    int ru = n - k;      // remaining zeros
    int rd = m;          // remaining ones
    int L = 0, U = k;    // boundaries
    while(ru + rd > 0){
        if(cur == U){ // at upper boundary, can only go down
            if(!feasibleDown(cur, ru, rd, L, F))
                return "";
            res[pos++] = '1';
            cur--;
            rd--;
        } else if(cur == L){ // at lower boundary, can only go up
            if(!feasibleUp(cur, ru, rd, U, F))
                return "";
            res[pos++] = '0';
            cur++;
            ru--;
        } else {
            bool upOk = feasibleUp(cur, ru, rd, U, F);
            bool downOk = feasibleDown(cur, ru, rd, L, F);
            if(upOk && downOk){
                // Choose the move that brings us closer to F.
                if(abs((cur+1) - F) <= abs((cur-1) - F)){
                    res[pos++] = '0';
                    cur++;
                    ru--;
                } else {
                    res[pos++] = '1';
                    cur--;
                    rd--;
                }
            } else if(upOk){
                res[pos++] = '0';
                cur++;
                ru--;
            } else if(downOk){
                res[pos++] = '1';
                cur--;
                rd--;
            } else {
                return "";
            }
        }
    }
    if(cur != F) return "";
    return res;
}
 
// Construct a valid string when F = n-m is negative.
// Allowed range is [-k, 0]. We force the minimum by starting with k ones.
string constructNegative(int F, int k, int n, int m) {
    // Must have m >= k and |F| <= k.
    if(m < k || -F > k) return "";
    int total = n + m;
    string res; res.resize(total);
    int pos = 0;
    // Force k ones.
    for (int i = 0; i < k; i++){
        res[pos++] = '1';
    }
    int cur = -k;         // current prefix sum
    int ru = n;           // remaining zeros
    int rd = m - k;       // remaining ones
    int L = -k, U = 0;    // boundaries
    while(ru + rd > 0){
        if(cur == L){ // at lower boundary, can only go up
            if(!feasibleUp(cur, ru, rd, U, F))
                return "";
            res[pos++] = '0';
            cur++;
            ru--;
        } else if(cur == U){ // at upper boundary, can only go down
            if(!feasibleDown(cur, ru, rd, L, F))
                return "";
            res[pos++] = '1';
            cur--;
            rd--;
        } else {
            bool upOk = feasibleUp(cur, ru, rd, U, F);
            bool downOk = feasibleDown(cur, ru, rd, L, F);
            if(upOk && downOk){
                if(abs((cur+1) - F) <= abs((cur-1) - F)){
                    res[pos++] = '0';
                    cur++;
                    ru--;
                } else {
                    res[pos++] = '1';
                    cur--;
                    rd--;
                }
            } else if(upOk){
                res[pos++] = '0';
                cur++;
                ru--;
            } else if(downOk){
                res[pos++] = '1';
                cur--;
                rd--;
            } else {
                return "";
            }
        }
    }
    if(cur != F) return "";
    return res;
}
 
// Main
// Reads t test cases and for each constructs a binary string (or outputs -1 if impossible).
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int total = n + m;
        // Special handling for pure cases.
        if(n == 0){
            // Only ones; the path is 0, -1, -2, ... so range = m.
            if(k == m)
                cout << string(m, '1') << "\n";
            else
                cout << -1 << "\n";
            continue;
        }
        if(m == 0){
            // Only zeros; the path is 0, +1, +2, ... so range = n.
            if(k == n)
                cout << string(n, '0') << "\n";
            else
                cout << -1 << "\n";
            continue;
        }
 
        // F is the final difference = n - m.
        int F = n - m;
        // A necessary condition is that k >= |F|.
        if(abs(F) > k){
            cout << -1 << "\n";
            continue;
        }
 
        string ans;
        if(F >= 0) {
            // We use the allowed interval [0, k] and force a hit to k.
            // For that, we need n >= k.
            if(n < k) {
                cout << -1 << "\n";
                continue;
            }
            ans = constructNonNegative(F, k, n, m);
        } else {
            // F < 0: use allowed interval [-k, 0] and force a hit to -k.
            if(m < k) {
                cout << -1 << "\n";
                continue;
            }
            ans = constructNegative(F, k, n, m);
        }
        if(ans == "" || (int)ans.size() != total)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
