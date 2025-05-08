#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
using ll = long long;
const int mod = 1000000007;
const char nl = '\n';

#ifdef ONLINE_JUDGE
#define debug(x...)
#else
#include "debug.cpp"
#endif

void hello() {
    string s;
    cin >> s;
    vector<int> temp(10), res(10, 0);
    iota(temp.begin(), temp.end(), 0);
    reverse(temp.begin(), temp.end());
    for(char c : s) 
        res[c - '0']++;
    string ans;
    for(int i = 0; i < 10; i++) {
        for(int d = temp[i]; d < 10; d++)
            if(res[d] > 0) {
                res[d]--;
                multiset<int> st;
                for(int k = 0; k < 10; k++)
                    for(int c = 0; c < res[k]; c++)
                        st.insert(k);
                bool ok = true;
                for(int j = i + 1; j < 10; j++) {
                    auto pos = st.lower_bound(temp[j]);
                    if(pos == st.end()) {
                        ok = false;
                        break;
                    }
                    st.erase(pos);
                }
                if(ok) {
                    ans.push_back('0' + d);
                    break;
                }
                res[d]++;
            }
    }
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test;
    cin >> test;
    while(test--) {
        hello();
    }
    return 0;
}