#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) (v).begin(), (v).end()

// Function to compute GCD
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Sparse Table for GCD
struct SparseTable {
    vector<vector<int>> table;
    vector<int> log;

    SparseTable(const vector<int>& arr) {
        int n = arr.size();
        log.resize(n + 1);
        log[1] = 0;
        for (int i = 2; i <= n; i++) 
            log[i] = log[i / 2] + 1;

        table.resize(log[n] + 1, vector<int>(n));
        for (int i = 0; i < n; i++) 
            table[0][i] = arr[i];

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                table[j][i] = gcd(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int query(int l, int r) {
        int j = log[r - l + 1];
        return gcd(table[j][l], table[j][r - (1 << j) + 1]);
    }
};

int32_t main() {
    int t;
    cin >> t;
    while(t--){
        int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    if (n == 1) {
        while (q--) {
            cout << 0 << '\n'; // Single element, m can be infinite
        }
        return 0;
    }

    vector<int> diff(n - 1);
    for (int i = 1; i < n; i++) 
        diff[i - 1] = abs(a[i] - a[i - 1]);

    SparseTable st(diff);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--; // 0-based indexing

        if (l == r) {
            cout << 0 << '\n'; // Single element
        } else {
            cout << st.query(l, r - 1) << '\n';
        }
    }
}

    return 0;
}
