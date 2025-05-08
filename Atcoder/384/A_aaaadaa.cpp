#include<bits/stdc++.h>
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

#define int int64_t
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define rrep(i, a, b) for(int i = a; i >= b; --i)

//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

template <class T> bool setmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template <class T> bool setmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}

void dxt(int test_case);
void pre_pro();
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    pre_pro();
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        dxt(i);
    }
    return 0;
}
template <class T> struct BIT { //1-indexed
  int n; vector<T> t;
  BIT() {}
  BIT(int _n) {
    n = _n; t.assign(n + 1, 0);
  }
  T query(int i) {
    T ans = 0;
    for (; i >= 1; i -= (i & -i)) ans += t[i];
    return ans;
  }
  void upd(int i, T val) {
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) t[i] += val;
  }
  void upd(int l, int r, T val) {
    upd(l, val);
    upd(r + 1, -val);
  }
  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};
template<class T> T floor_div(T x, T y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x >= 0) return x / y;
    return (x + 1) / y - 1;
}
 template <class T> T ceil_div(T x, T y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x <= 0) return x / y;
    return (x - 1) / y + 1;
}

struct mint{
    int val;
    mint(long long v = 0) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; }
    static int mod_inv(int a, int m = MOD) { int g = m, r = a, x = 0, y = 1; while (r != 0) { int q = g / r; g %= r; swap(g, r); x -= q * y; swap(x, y); } return x < 0 ? x + m : x; }
    explicit operator int() const { return val; }
    mint &operator+=(const mint &other) { val += other.val; if (val >= MOD) val -= MOD; return *this; }
    mint &operator-=(const mint &other) { val -= other.val; if (val < 0) val += MOD; return *this; }
    typedef unsigned long long ull;
    ull fast_mod(ull a, ull b, ull M = MOD) { long long ret = a * b - M * ull(1.L / M * a * b); return ret + M * (ret < 0) - M * (ret >= (long long)M); }
    mint &operator*=(const mint &other) { val = fast_mod((ull)val, other.val); return *this; }
    mint &operator/=(const mint &other) { return *this *= other.inv(); }
    friend mint operator+(const mint &a, const mint &b) { return mint(a) += b; }
    friend mint operator-(const mint &a, const mint &b) { return mint(a) -= b; }
    friend mint operator*(const mint &a, const mint &b) { return mint(a) *= b; }
    friend mint operator/(const mint &a, const mint &b) { return mint(a) /= b; }
    mint &operator++() { val = val == MOD - 1 ? 0 : val + 1; return *this; }
    mint &operator--() { val = val == 0 ? MOD - 1 : val - 1; return *this; }
    mint operator++(int32_t) { mint before = *this; ++*this; return before; }
    mint operator--(int32_t) { mint before = *this; --*this; return before; }
    mint operator-() const { return val == 0 ? 0 : MOD - val; }
    bool operator==(const mint &other) const { return val == other.val; }
    bool operator!=(const mint &other) const { return val != other.val; }
    mint inv() const { return mod_inv(val); }
    mint pow(long long p) const { assert(p >= 0); mint a = *this, result = 1; while (p > 0) { if (p & 1) result *= a; a *= a; p >>= 1; } return result; }
    friend ostream &operator<<(ostream &stream, const mint &m) { return stream << m.val; }
    friend istream &operator>>(istream &stream, mint &m) { return stream >> m.val; }
    friend void __print(const mint &x) { cerr << x.val; }
};

const int maxn = 100100;
mint fact[maxn], invf[maxn];
mint C(int n, int r){
    assert(n >= r && r >= 0);
    if(r == 0)
        return mint(1);
    return fact[n] * invf[r] * (invf[n - r]);
}
void bincof(int a, int b){
    fact[0] = 1;
    for(int i = 1; i <= maxn; ++i){
        fact[i] = fact[i - 1] * i;
        invf[i] = mint(fact[i]).inv();
    }
}

template <class T> int fsqrt(T n) {
    if (n == 0 || n == 1) return n;

    int low = 0, high = 5000000000, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid * mid == n) return mid;
        else if (mid * mid < n) {
            low = mid + 1;
            ans = mid;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int64_t fastPow(int64_t a, int64_t b){
    int64_t res = 1;
    while(b){
        if(b & 1){
            res = res * a ;
        }
        a = (a * a);
        b >>= 1;
    }
    return res;
}

template<typename T> using MaxHeap = std::priority_queue<T>;
template<typename T> using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;



vector<vector<int>> pref(26, vector<int>(n, 0));

for(int i = 0; i < n; ++i){
    for(int j = 0; j < 26 && i > 0; ++j){
        pref[j][i] = pref[j][i - 1];
    }
    pref[s[i] - 'a'][i]++;
}


void pre_pro(){
}
void dxt(int test_case){
    int n; cin >> n;
    char c1, c2;
    cin >> c1 >> c2;
    
    string s;
    cin >> s;

    for(auto &x : s){
        if(x != c1) x = c2;
    }
    cout << s << endl;
}