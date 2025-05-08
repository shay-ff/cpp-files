/**
*    created: 2025-03-17 21:12:00
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
vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    set<string> st(words.begin(),words.end());
    sort(words.begin(),words.end(), [&](auto &a, auto &b){
        return a.size() < b.size();
    });
    vector<string> answer;
    function <bool(string&, vector<int>&, int idx)> solve = [&](string &curr, vector<int> &dp, int idx){
        if(idx == curr.size()){
            return true;
        }
        if(dp[idx] != -1) return dp[idx];
        string temp = "";
        for(int i = idx; i < curr.size(); ++i){
            temp += curr[i];
            if(st.count(temp)){
                if (solve(curr, dp, i + 1)) {
                    dp[idx] = 1;
                    return true;
                }
            }
        }
        dp[idx] = 0;
        return false;
    };
    for(int i = 0; i < words.size(); ++i){
        string pref = "", curr = words[i];
        for(int j = 0; j < curr.size(); ++j){
            pref += curr[j];
            if(st.count(pref) && pref != curr){
                if (solve(curr, dp, j + 1)) {
                    answer.push_back(curr);
                    break;
                }
                if(ans == 1) answer.push_back(curr);
            }
        }
    }
    return answer;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x : a){
            cin >> x;
        }
        BIT<int> bit(n);
        // count inversion in a
        int inv = 0;
        for(int i = 0; i < n; ++i){
            inv += bit.query(a[i] + 1, n);
            bit.upd(a[i], 1);
        }
        cout << inv << endl;

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}