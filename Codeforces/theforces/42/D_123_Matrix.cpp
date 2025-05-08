/**
*    created: 2025-04-08 17:11:52
**/
#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())

const int MOD = 998244353;
struct mint {
    int val;
    mint(long long v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
        return x < 0 ? x + m : x;
    }
    explicit operator int() const { return val; }
    mint &operator+=(const mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    mint &operator-=(const mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    typedef unsigned long long ull;
    ull fast_mod(ull a, ull b, ull M = MOD) {
        long long ret = a * b - M * ull(1.L / M * a * b);
        return ret + M * (ret < 0) - M * (ret >= (long long)M);
    }
    mint &operator*=(const mint &other) {
        val = fast_mod((ull)val, other.val);
        return *this;
    }
    mint &operator/=(const mint &other) {
        return *this *= other.inv();
    }
    friend mint operator+(const mint &a, const mint &b) {
        return mint(a) += b;
    }
    friend mint operator-(const mint &a, const mint &b) {
        return mint(a) -= b;
    }
    friend mint operator*(const mint &a, const mint &b) {
        return mint(a) *= b;
    }
    friend mint operator/(const mint &a, const mint &b) {
        return mint(a) /= b;
    }
    mint &operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    mint &operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    mint operator++(int32_t) {
        mint before = *this;
        ++*this;
        return before;
    }
    mint operator--(int32_t) {
        mint before = *this;
        --*this;
        return before;
    }
    mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const mint &other) const {
        return val == other.val;
    }
    bool operator!=(const mint &other) const {
        return val != other.val;
    }
    mint inv() const {
        return mod_inv(val);
    }
    mint pow(long long p) const {
        assert(p >= 0);
        mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1) result *= a;
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream &operator<<(ostream &stream, const mint &m) {
        return stream << m.val;
    }
    friend istream &operator>>(istream &stream, mint &m) {
        return stream >> m.val;
    }
    friend void __print(const mint &x) {
        cerr << x.val;
    }
};

const int maxn = 1001001;
mint fact[maxn], invf[maxn];
mint C(int n, int r) {
    assert(n >= r && r >= 0);
    if (r == 0)
        return mint(1);
    return fact[n] * invf[r] * (invf[n - r]);
}
void bincof() {
    fact[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fact[i] = fact[i - 1] * i;
        invf[i] = mint(fact[i]).inv();
    }
}

signed main(){
    bincof();
    vector<mint> prec(maxn), S(maxn);
    S[0] = invf[0];  // Which should be 1 because fact[0] == 1.
    for (int n = 1; n < maxn; ++n) {
        // (-1)^n is achieved by: (n % 2 ? -1 : 1)
        S[n] = S[n-1] + (n % 2 ? -invf[n] : invf[n]);
        prec[n] = S[n] * fact[n] * fact[n];
    }
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;

        if(n & 1){
            if(n == 1){
                cout << 0 << endl;
            }
            else{
                cout << prec[n] << endl;
            }
        }
        else{
            cout << 1 << endl;
        }
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}