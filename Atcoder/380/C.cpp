#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Constants for test case generation
const int N = 100000;  // Maximum allowed points
const ll MAX_COORD = 1000000000000LL;  // 10^12
const ll MAX_COST = 1000000000LL;      // 10^9

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// Generate random number in range [l, r]
ll rand_range(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // First, let's create the actual test case file
    ofstream out("huge_test.txt");
    
    // Generate n close to maximum to stress test
    int n = N;
    out << n << "\n";
    
    // Generate coordinates with specific patterns to create challenging scenarios
    vector<ll> coords(n);
    
    // Create different patterns in different regions
    int curr_pos = 0;
    
    // Pattern 1: Very close points (20% of points)
    int close_points = n/5;
    for(int i = 0; i < close_points; i++) {
        coords[curr_pos++] = i;
    }
    
    // Pattern 2: Exponentially spaced points (20% of points)
    int exp_points = n/5;
    ll curr_coord = close_points + 1;
    for(int i = 0; i < exp_points; i++) {
        coords[curr_pos++] = curr_coord;
        curr_coord *= 2;
        if(curr_coord > MAX_COORD) curr_coord = MAX_COORD;
    }
    
    // Pattern 3: Random large gaps (20% of points)
    int gap_points = n/5;
    curr_coord = curr_coord + 1000000;
    for(int i = 0; i < gap_points; i++) {
        coords[curr_pos++] = curr_coord;
        curr_coord += rand_range(1000000, 10000000);
        if(curr_coord > MAX_COORD) curr_coord = MAX_COORD;
    }
    
    // Pattern 4: Clustered points (20% of points)
    int cluster_points = n/5;
    for(int i = 0; i < cluster_points/10; i++) {  // 10 clusters
        ll cluster_center = rand_range(curr_coord + 1000000, MAX_COORD - 1000000);
        for(int j = 0; j < 10; j++) {  // 10 points per cluster
            coords[curr_pos++] = cluster_center + rand_range(-100, 100);
        }
    }
    
    // Pattern 5: Fill remaining with random points
    while(curr_pos < n) {
        coords[curr_pos++] = rand_range(0, MAX_COORD);
    }
    
    // Sort coordinates
    sort(coords.begin(), coords.end());
    
    // Remove any duplicates
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    
    // If we removed duplicates, add new random points
    while(coords.size() < n) {
        ll new_coord = rand_range(0, MAX_COORD);
        coords.push_back(new_coord);
    }
    
    // Sort again after adding new points
    sort(coords.begin(), coords.end());
    
    // Output coordinates
    for(int i = 0; i < n; i++) {
        out << coords[i] << " \n"[i == n-1];
    }
    
    // Generate costs with specific patterns
    vector<ll> costs(n);
    
    // Pattern 1: Some very low costs (10% of points)
    for(int i = 0; i < n/10; i++) {
        costs[i] = rand_range(1, 100);
    }
    
    // Pattern 2: Some very high costs (10% of points)
    for(int i = n/10; i < n/5; i++) {
        costs[i] = rand_range(MAX_COST-100, MAX_COST);
    }
    
    // Pattern 3: Remaining with random costs
    for(int i = n/5; i < n; i++) {
        costs[i] = rand_range(1000, MAX_COST-1000);
    }
    
    // Shuffle costs to make it more interesting
    shuffle(costs.begin(), costs.end(), rng);
    
    // Output costs
    for(int i = 0; i < n; i++) {
        out << costs[i] << " \n"[i == n-1];
    }
    
    // Also create a smaller version for validation
    ofstream out_small("small_test.txt");
    out_small << "10\n";
    for(int i = 0; i < 10; i++) {
        out_small << coords[i] << " \n"[i == 9];
    }
    for(int i = 0; i < 10; i++) {
        out_small << costs[i] << " \n"[i == 9];
    }
    
    // Print some statistics
    cout << "Test case generation completed!\n";
    cout << "Number of points: " << n << "\n";
    cout << "Coordinate range: [" << coords[0] << ", " << coords[n-1] << "]\n";
    cout << "Cost range: [" << *min_element(costs.begin(), costs.end()) 
         << ", " << *max_element(costs.begin(), costs.end()) << "]\n";
    
    return 0;
}