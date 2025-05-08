#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    if (k == 1){
        cout << n << "\n";
        return 0;
    }

    // build rolling hash base B
    const ull B = 1000000007ULL;
    vector<ull> H(n+1), P(n+1);
    P[0] = 1;
    for(int i = 0; i < n; i++){
        P[i+1] = P[i] * B;
        H[i+1] = H[i]*B + (unsigned char)(s[i]);
    }
    auto get_hash = [&](int i, int len){
        // hash of s[i..i+len-1]
        return H[i+len] - H[i]*P[len];
    };

    auto can = [&](int L){
        // map hash -> (last_chosen_start, count_of_chosen)
        unordered_map<ull, pair<int,int>> mp;
        mp.reserve(n - L + 1);
        for(int i = 0; i + L <= n; i++){
            ull h = get_hash(i, L);
            auto &st = mp[h];
            if (st.second == 0) {
                // first time we've seen this hash
                st = { i, 1 };
            } else if (i >= st.first + L) {
                // disjoint from the last chosen
                st = { i, st.second + 1 };
                if (st.second >= k) return true;
            }
        }
        return false;
    };

    int lo = 1, hi = n / k, ans = 0;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if (can(mid)){
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
