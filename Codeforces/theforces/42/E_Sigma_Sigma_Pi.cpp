/**
*    created: 2025-04-08 17:41:39
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
const int MOD = 1000000007;
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

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> factors(21);
    for(int p = 1; p <= 20; ++p){
        int cntr = 0;
        for(int i = 1; i * i <= p; ++i){
            if(p % i == 0){
                cntr++;
                if(i != p / i){
                    cntr++;
                }
            }
        }
        factors[p] = cntr;
    }
    auto factor = [&](mint x){
        int count = 0;
        int y = x;
        for(int i = 1; i * i <= y; ++i){
            if(y % i == 0){
                count++;
                if(i != y / i){
                    count++;
                }
            }
        }
        return count;
    };
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        vector<int> prod(n);
        for(int i = 0; i < n; ++i){
            i ? prod[i] = prod[i - 1] * a[i] : prod[i] = a[i];
        }
        /*
        ∑𝑙=1𝑛∑𝑟=𝑙𝑛𝑓(∏𝑖=𝑙𝑟𝑎𝑖)
        */
        mint ans = 0;
        for(int l = 0; l < n; ++l){
            for(int r = l; r < n; ++r){
                int f = factor(prod[r] / (l ? prod[l - 1] : 1));
                ans += f;
            }
        }
        cout << ans << endl;
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}