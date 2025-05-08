#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// Define the modulus for the final output
const ll MOD = 1e9 + 7;

// Function to multiply two matrices and return result modulo m (including MOD)
vector<vector<ll>> matrixMultiply(const vector<vector<ll>>& A, const vector<vector<ll>>& B, ll m) {
    return {
        {(A[0][0] * B[0][0] + A[0][1] * B[1][0]) % m, (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % m},
        {(A[1][0] * B[0][0] + A[1][1] * B[1][0]) % m, (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % m}
    };
}

// Function to calculate matrix exponentiation: base^exp % mod
vector<vector<ll>> matrixPower(vector<vector<ll>> base, ll exp, ll mod) {
    vector<vector<ll>> result = {{1, 0}, {0, 1}};  // Identity matrix
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = matrixMultiply(result, base, mod);
        }
        base = matrixMultiply(base, base, mod);
        exp /= 2;
    }
    return result;
}

// Function to compute the n-th Fibonacci number modulo m (including MOD)
ll fibonacciMod(ll n, ll m) {
    if (n == 0) return 0;
    vector<vector<ll>> F = {{1, 1}, {1, 0}};
    vector<vector<ll>> result = matrixPower(F, n - 1, m);
    return result[0][0] % m;
}

// Function to calculate the Pisano period for a given k
ll pisano_period(ll k) {
    ll f1 = 0, f2 = 1;
    for (ll i = 0; i < k * k; ++i) {
        ll f3 = (f1 + f2) % k;
        f1 = f2;
        f2 = f3;
        if (f1 == 0 && f2 == 1) return i + 1;  // Pisano period detected
    }
    return 0;  // This should never happen as Pisano period exists
}

// Function to find the n-th Fibonacci number divisible by k (all mod MOD)
ll findPosition(ll k, ll n) {
    // Calculate Pisano period for the given k
    ll period = pisano_period(k);

    // Find the position within the Pisano period
    ll reduced_n = n % period;
    
    // Compute Fibonacci number at that position modulo k
    ll fib_num_mod_k = fibonacciMod(reduced_n, k);
    
    // Return the result modulo MOD
    return fib_num_mod_k % MOD;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << findPosition(k, n) << endl;
    }
}
