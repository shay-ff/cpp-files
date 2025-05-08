#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long solve_test_case(int n, vector<int>& a, vector<int>& b) {
    // Special case for single column
    if (n == 1) return max(a[0], b[0]);

    // Key insight: create a score-based sorting strategy
    vector<pair<int, int>> scores(n);
    for (int i = 0; i < n; i++) {
        // Score = difference between second and first row values
        scores[i] = {b[i] - a[i], i};
    }

    // Sort scores descending, effectively moving larger value columns to the right
    sort(scores.rbegin(), scores.rend());

    // Rearrange columns based on sorted scores
    vector<int> new_a(n), new_b(n);
    for (int i = 0; i < n; i++) {
        new_a[i] = a[scores[i].second];
        new_b[i] = b[scores[i].second];
    }

    // DP to find maximum path
    vector<vector<long long>> dp(2, vector<long long>(n, LLONG_MIN));
    
    // Initialize first cell
    dp[0][0] = new_a[0];

    // First row path
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + new_a[j];
    }

    // Add vertical and diagonal moves
    for (int j = 1; j < n; j++) {
        dp[1][j] = max(dp[0][j-1], dp[0][j]) + new_b[j];
    }

    // Return maximum path sum
    return dp[1][n-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        char a = 'a';
    }

    return 0;
}