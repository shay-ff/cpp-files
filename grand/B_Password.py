#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1000000007;
const int hashPrime = 31;

int modExp(int base, int exp, int mod) {
    int result = 1;
    while(exp > 0) {
        if(exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

class RollingHash {
    vector<int> prefix;
    vector<int> p_pow;
    vector<int> inv_p_pow;
    int n;
public:
    RollingHash(const string &st) {
        n = st.size();
        prefix.resize(n + 1, 0);
        p_pow.resize(n, 0);
        inv_p_pow.resize(n, 0);
        
        // Precompute powers of hashPrime.
        p_pow[0] = 1;
        for (int i = 1; i < n; i++) {
            p_pow[i] = (p_pow[i - 1] * hashPrime) % mod;
        }
        
        // Precompute modular inverses of powers.
        for (int i = 0; i < n; i++) {
            inv_p_pow[i] = modExp(p_pow[i], mod - 2, mod);
        }
        
        // Build prefix hash array.
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = (prefix[i] + (st[i] - 'a' + 1) * p_pow[i]) % mod;
        }
    }
    
    // Returns the hash of the substring [l, r] in normalized form.
    int getHash(int l, int r) {
        int hash_val = (prefix[r + 1] - prefix[l] + mod) % mod;
        // Multiply by inverse of p_pow[l] to normalize (bring substring's hash to "power 0")
        hash_val = (hash_val * inv_p_pow[l]) % mod;
        return hash_val;
    }
};

class Solution {
public:
    void solve() {
        string st;
        cin >> st;
        int n = st.size();
        RollingHash rh(st);

        // Collect candidate lengths (borders) where the prefix equals the suffix.
        vector<int> candidate;
        for (int len = 1; len < n; len++) {
            if (rh.getHash(0, len - 1) == rh.getHash(n - len, n - 1)) {
                candidate.push_back(len);
            }
        }
        
        // Binary search over candidate border lengths.
        int ans = -1;
        int lo = 0, hi = candidate.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int L = candidate[mid];
            bool found = false;
            // Check if pattern of length L occurs in the middle (not at the beginning or end).
            for (int i = 1; i <= n - L - 1; i++) {
                if (rh.getHash(i, i + L - 1) == rh.getHash(0, L - 1)) {
                    found = true;
                    break;
                }
            }
            if (found) {
                ans = L;
                lo = mid + 1; // Try to find a longer border.
            } else {
                hi = mid - 1;
            }
        }
        
        if (ans == -1)
            cout << "Just a legend";
        else
            cout << st.substr(0, ans);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCases = 1;
    while (testCases--) {
        Solution obj;
        obj.solve();
    }
    return 0;
}
