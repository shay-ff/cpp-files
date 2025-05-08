#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 6;
const double INF = 1e9;

// Input variables
int N;
double S, T;
vector<pair<pair<double, double>, pair<double, double>>> segments;

// Distance calculation between two points
double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Memoization table
double memo[1 << MAXN][MAXN][2];

// Recursive function to calculate the minimum time
double solve(int mask, int last, bool isStart) {
    if (mask == (1 << N) - 1) {
        return 0;  // All segments are printed
    }

    // If already calculated, return the stored result
    if (memo[mask][last][isStart] != -1) {
        return memo[mask][last][isStart];
    }

    double x = isStart ? segments[last].first.first : segments[last].second.first;
    double y = isStart ? segments[last].first.second : segments[last].second.second;

    double res = INF;

    // Try to move to the next segment
    for (int i = 0; i < N; i++) {
        if (mask & (1 << i)) continue;  // Already printed this segment

        // Try moving to the start of segment i
        double distToStart = dist(x, y, segments[i].first.first, segments[i].first.second) / S;
        double laserDist = dist(segments[i].first.first, segments[i].first.second, segments[i].second.first, segments[i].second.second) / T;
        res = min(res, distToStart + laserDist + solve(mask | (1 << i), i, true));

        // Try moving to the end of segment i
        double distToEnd = dist(x, y, segments[i].second.first, segments[i].second.second) / S;
        res = min(res, distToEnd + laserDist + solve(mask | (1 << i), i, false));
    }

    cout << "Mask: " << mask << ", Last: " << last << ", isStart: " << isStart << " -> Result: " << res << endl;  // Debug log

    return memo[mask][last][isStart] = res;
}

int main() {
    // Input: number of segments and speeds S and T
    cin >> N >> S >> T;

    segments.resize(N);
    
    // Input: each line segment (A_i, B_i), (C_i, D_i)
    for (int i = 0; i < N; i++) {
        cin >> segments[i].first.first >> segments[i].first.second;
        cin >> segments[i].second.first >> segments[i].second.second;
    }

    // Initialize memoization table with -1
    memset(memo, -1, sizeof(memo));

    double result = INF;

    // Start recursion from (0, 0), try moving to the start or end of each segment
    for (int i = 0; i < N; i++) {
        // Move to the start of segment i from (0, 0)
        double distToStart = dist(0, 0, segments[i].first.first, segments[i].first.second) / S;
        double laserDist = dist(segments[i].first.first, segments[i].first.second, segments[i].second.first, segments[i].second.second) / T;
        result = min(result, distToStart + laserDist + solve(1 << i, i, true));

        // Move to the end of segment i from (0, 0)
        double distToEnd = dist(0, 0, segments[i].second.first, segments[i].second.second) / S;
        result = min(result, distToEnd + laserDist + solve(1 << i, i, false));
    }

    // Output the result
    cout << fixed << result << endl;

    return 0;
}
