#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long int;
const int naxn = 500500;
bool is_prime[naxn + 10];

void findPrimes(int maxLimit) {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= maxLimit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxLimit; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void dxt() {
    int n;
    cin >> n;

    if (n < 5) {
        cout << -1 << endl;
        return;
    }

    for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
    }

    int x = n;
    if (x & 1) x--;

    int ans = -1;
    for (int i = 1; i <= n; i += 2) {
        debug(is_prime[x + i], x + i);
        if (!is_prime[x + i]) {
            ans = i;
            break;
        }
    }

    int j;
    for (j = ans; j >= 1; j -= 2) {
        cout << j << " ";
    }

    j = ans + 2;
    for (; j <= n; j += 2) {
        cout << j << " ";
    }
    cout << endl;
}

int main() {
    findPrimes(naxn + 10);
    int t;
    cin >> t;
    while (t--) {
        dxt();
    }
}
