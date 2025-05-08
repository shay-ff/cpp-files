#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <cmath> 
#include <climits> 
using namespace std; 
void solve() { 
 int T; 
 cin >> T; 
 while (T--) { 
 int N, X; 
 cin >> N >> X; 
 vector<int> B(N); 
 for (int i = 0; i < N; ++i) { 
 cin >> B[i]; 
 } 
 if (N == 1) { 
 // Only one problem, no change needed 
 cout << "0" << endl; 
 cout << B[0] << endl; 
 continue; 
 } 
 // Binary search for the minimum K 
 int lowK = 0, highK = 2 * 1e9, answerK = highK; 
  
 while (lowK <= highK) {

int midK = (lowK + highK) / 2; 
 bool feasible = true; 
 int prev_low = B[0] - midK; 
 int prev_high = B[0] + midK; 
 for (int i = 1; i < N; ++i) { 
 int current_low = max(B[i] - midK, prev_low); 
 int current_high = min(B[i] + midK, prev_high + X); 
 if (current_low > current_high) { 
 feasible = false; 
 break; 
 } 
 prev_low = current_low; 
 prev_high = current_high; 
 } 
 if (feasible) { 
 answerK = midK; 
 highK = midK - 1; 
 } else { 
 lowK = midK + 1; 
 } 
 } 
 // Reconstruct the C sequence with the found answerK 
 vector<pair<int, int>> ranges(N); 
 ranges[0] = {B[0] - answerK, B[0] + answerK};

for (int i = 1; i < N; ++i) { 
 int new_low = max(B[i] - answerK, ranges[i-1].first); 
 int new_high = min(B[i] + answerK, ranges[i-1].second + X); 
 ranges[i] = {new_low, new_high}; 
 } 
 // Backward pass to set the C sequence 
 vector<int> C(N); 
 C[N-1] = ranges[N-1].second; 
 for (int i = N - 2; i >= 0; --i) { 
 C[i] = min(ranges[i].second, C[i+1]); 
 C[i] = max(C[i], ranges[i].first); 
 } 
 // Now, find the maximum |Ci - Bi| 
 int K_final = 0; 
 for (int i = 0; i < N; ++i) { 
 int diff = abs(C[i] - B[i]); 
 if (diff > K_final) { 
 K_final = diff; 
 } 
 } 
 // Output the results 
 cout << K_final << endl; 
 for (int i = 0; i < N; ++i) { 
 cout << C[i] << " "; 
 } 
 cout << endl; 
 }
} 
int main() { 
 ios_base::sync_with_stdio(false); 
 cin.tie(0); 
 solve(); 
 return 0; 
}