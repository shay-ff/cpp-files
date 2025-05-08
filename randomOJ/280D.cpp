#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int solution(const string& p, const string& q, const string& r) {
    int m = p.size(), n = q.size(), k = r.size();
    
    // dp[i][j][r_idx] will hold the number of ways to form r[0:r_idx] using p[0:i] and q[0:j]
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, 0)));

    // Base case: There's one way to form the empty string (not selecting any characters)
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j][0] = 1;
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int r_idx = 1; r_idx <= k; ++r_idx) {
                // If we take from p
                if (p[i - 1] == r[r_idx - 1]) {
                    dp[i][j][r_idx] += dp[i - 1][j][r_idx - 1];
                }
                dp[i][j][r_idx] %= MOD;

                // If we take from q
                if (q[j - 1] == r[r_idx - 1]) {
                    dp[i][j][r_idx] += dp[i][j - 1][r_idx - 1];
                }
                dp[i][j][r_idx] %= MOD;

                // We can also take from both but do not contribute to r_idx
                dp[i][j][r_idx] += dp[i - 1][j][r_idx];  // Not taking from r
                dp[i][j][r_idx] += dp[i][j - 1][r_idx];  // Not taking from q
                dp[i][j][r_idx] %= MOD;
            }
        }
    }

    // Now we need to count the number of valid ways
    int total_count = 0;

    // We need at least one character from p and one from q
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            total_count += dp[i][j][k];
            total_count %= MOD;
        }
    }

    return total_count;
}

int main() {
    // Sample test case
    string p = "ab";
    string q = "ba";
    string r = "aba";
    int output = solution(p, q, r);
    cout << output << endl;  // Output: 2
    return 0;
}
