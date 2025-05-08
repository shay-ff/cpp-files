/**
*    created: 2025-03-29 17:31:34
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
/*
N people labeled from 
1 to 
N participated in a certain contest. The score of person 
i (
1≤i≤N) was 
P 
i
​
 .

In this contest, the rank of each of the 
N people is determined by the following procedure:

Prepare a variable 
r, and initialize 
r=1. Initially, the ranks of the 
N people are all undetermined.
Repeat the following operation until the ranks of all 
N people are determined:
Let 
x be the maximum score among the people whose ranks are currently undetermined, and let 
k be the number of people whose score is 
x. Determine the rank of those 
k people with score 
x to be 
r, and then add 
k to 
r.
Print the rank of each of the 
N people.
maritovexi
*/
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int count1 = count(s.begin(), s.end(), '1');
        int q = queries.size();
        vector<int> answer(q, 0);

        for (int i = 0; i < q; ++i) {
            int l = queries[i][0], r = queries[i][1];
            string sub = s.substr(l, r - l + 1);
            string t = "1" + sub + "1";
            vector<pair<char, int>> segments;
            for (char c : t) {
                if (segments.empty() || segments.back().first != c)
                    segments.push_back({c, 1});
                else
                    segments.back().second++;
            }
            int maxGain = 0;
            for (size_t i = 0; i < segments.size(); i++) {
                if (segments[i].first == '1' && i > 0 && i < segments.size() - 1) {
                    int leftZeros = segments[i - 1].second;
                    int rightZeros = segments[i + 1].second;
                    maxGain = max(maxGain, leftZeros + rightZeros);
                }
            }
            answer[i] = count1 + maxGain;
        }
        return answer;
    }
};
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i = 0; i < n; ++i){
            cin >> p[i];
        }
        vector<int> r(n, 0);
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j){
            return p[i] > p[j];
        });
        int rank = 1;
        int i = 0;
        while(i < n){
            int curr = p[order[i]];
            int j = i;
            while(j < n && p[order[j]] == curr){
                j++;
            }
            int count = j - i;
            for(int k = i; k < j; ++k){
                r[order[k]] = rank;
            }
            rank += count;
            i = j;
        }
        for(int i = 0; i < n; ++i){
            cout << r[i] << "\n";
        }

    };
    int T = 1;
    // cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}