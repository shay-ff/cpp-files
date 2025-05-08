#include <bits/stdc++.h>
using namespace std;



int main() {
    const int T = 1000; // Number of test cases
    cout << T << "\n"; // Print the number of test cases

    // srand(time(0)); // Seed for randomness
    int total_k = 0; // Track the total sum of k across all test cases
    const int MAX_K = 200000; // Constraint for the total sum of k

    for (int t = 0; t < T; ++t) {
        // Ensure total_k does not exceed the constraint
        int remaining = MAX_K - total_k;
        int k = min(remaining, int(rand() % 5000 + 3)); // Random k in range [3, 5000]
        total_k += k;

        cout << k << "\n"; // Print k

        // Generate n and m such that n + 2m <= sum of some subset
        int n = rand() % (k / 2) + 1;
        int m = rand() % (k / 2) + n + 1;

        vector<int> a;
        a.push_back(n);
        a.push_back(m);

        // Fill the rest of the array with random values
        for (int i = 0; i < k - 2; ++i) {
            a.push_back(rand() % k + 1); // Random values between 1 and k
        }

        // Shuffle the array
        random_shuffle(a.begin(), a.end());

        // Print the array
        for (int x : a) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
