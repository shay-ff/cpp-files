#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

class FastCombinationCounter {
private:
    vector<vector<int>> curr, prev;
    int A, B, C;

    inline void safe_add(int& a, long long b) {
        a = (a + b) % MOD;
    }

public:
    FastCombinationCounter(int a, int b, int c) : A(a), B(b), C(c) {
        prev.resize(B, vector<int>(C + 1, 0));
        curr.resize(B, vector<int>(C + 1, 0));
    }

    int calculate() {
        // Base case: first element, 0 changes, all colors are valid once
        for (int j = 0; j < B; ++j) {
            prev[j][0] = 1;
        }

        for (int i = 2; i <= A; ++i) {
            // Reset current state to zero
            for (auto& row : curr) {
                fill(row.begin(), row.end(), 0);
            }

            // Precompute total_prev[changes] = sum(prev[k][changes] for all k)
            vector<int> total_prev(C + 1, 0);
            for (int changes = 0; changes <= C; ++changes) {
                for (int k = 0; k < B; ++k) {
                    total_prev[changes] = (total_prev[changes] + prev[k][changes]) % MOD;
                }
            }

            // Compute current state using the precomputed totals
            for (int j = 0; j < B; ++j) {
                for (int changes = 0; changes <= C; ++changes) {
                    long long same = prev[j][changes];
                    long long different = 0;
                    if (changes > 0) {
                        different = (total_prev[changes - 1] - prev[j][changes - 1] + MOD) % MOD;
                    }
                    curr[j][changes] = (same + different) % MOD;
                }
            }

            // Swap previous and current states for the next iteration
            swap(prev, curr);
        }

        // Sum up all valid sequences ending with any color and exactly C changes
        int total = 0;
        for (int j = 0; j < B; ++j) {
            safe_add(total, prev[j][C]);
        }
        return total;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;
    
    FastCombinationCounter counter(A, B, C);
    cout << counter.calculate() << endl;

    return 0;
}