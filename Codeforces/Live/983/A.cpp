#include <bits/stdc++.h>
using namespace std;

class Solver {
public:
    vector<vector<int>> solve(int n, int k) {
        // Deterministic construction strategy
        int m = 2 * k - 1;  // number of subarrays
        
        // Compute subarray length
        int subarray_length = max(1, (n / m) * 2 + 1);
        subarray_length = min(subarray_length, n);
        
        vector<vector<int>> subarrays;
        int current = 1;
        
        for (int i = 0; i < m && current <= n; ++i) {
            // Precise subarray generation
            int end = min(current + subarray_length - 1, n);
            
            vector<int> subarray;
            for (int j = current; j <= end; ++j) {
                subarray.push_back(j);
            }
            
            // Ensure odd length and within bounds
            if (subarray.size() % 2 == 1) {
                subarrays.push_back(subarray);
            }
            
            current = end + 1;
        }
        
        // Verify median of medians
        if (verify_solution(n, k, subarrays)) {
            return subarrays;
        }
        
        return {};  // No solution
    }
    
private:
    bool verify_solution(int n, int k, vector<vector<int>>& subarrays) {
        // Quick verification
        vector<int> medians;
        
        for (auto& subarray : subarrays) {
            // Find median efficiently
            int median_idx = (subarray.size() - 1) / 2;
            nth_element(subarray.begin(), subarray.begin() + median_idx, subarray.end());
            medians.push_back(subarray[median_idx]);
        }
        
        // Sort and find median of medians
        nth_element(medians.begin(), medians.begin() + (medians.size() - 1) / 2, medians.end());
        int median_of_medians = medians[(medians.size() - 1) / 2];
        
        // Validate solution
        return (median_of_medians == k);
    }
};

// Stress test and main function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solver solver;
    
    // Test cases
    vector<pair<int, int>> test_cases = {
        {1, 1},     // Small case
        {3, 2},  // Medium case
        {3, 3}  // Large case
    };
    
    for (auto [n, k] : test_cases) {
        auto start = chrono::high_resolution_clock::now();
        
        auto result = solver.solve(n, k);
        
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        
        if (!result.empty()) {
            cout << "Solution found for n=" << n << ", k=" << k << endl;
            
            // Optional: Print solution details
            cout << "Number of subarrays: " << result.size() << endl;
            
            // Validate medians
            vector<int> medians;
            for (auto& subarray : result) {
                int median_idx = (subarray.size() - 1) / 2;
                medians.push_back(subarray[median_idx]);
            }
            
            sort(medians.begin(), medians.end());
            int median_of_medians = medians[(medians.size() - 1) / 2];
            
            assert(median_of_medians == k);
            cout << "Median of medians: " << median_of_medians << endl;
        } else {
            cout << "No solution for n=" << n << ", k=" << k << endl;
        }
        
        cout << "Execution time: " << duration.count() << " microseconds" << endl << endl;
    }
    
    return 0;
}