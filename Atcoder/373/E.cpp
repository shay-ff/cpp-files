#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif


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

void pre_pro(){
}
   int countOfSubstrings(string word, int k) {
        int n = word.size();
        int conso = 0, ans = 0, L = 0;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        map<char, int> vowc;
        set<pair<int,int>> have;
        auto allVowelsPresent = [&](map<char, int>& vowc) {
            for (auto& x : vowels) {
                if (vowc[x] == 0)
                    return false;
            }
            return true;
        };
        int R;
        for (R = 0; R < n; ++R) {
            char curr = word[R];

            if (vowels.count(curr)) {
                vowc[curr]++;
            } else {
                conso++;
            }

            while (conso > k) {
                char temp = word[L];
                if (vowels.count(temp)) {
                    vowc[temp]--;
                } else {
                    conso--;
                }
                L++;
            }
            // debug(L, R, conso);
            if (conso == k && allVowelsPresent(vowc)) {
                // debug(L, R);
                // debug(vowc);

                ans += (!have.count({L,R}));
                debug(have.count({L,R}), have);
                have.insert({L, R});
            }
        }
        // while (L < n) {
        //     if (vowels.count(word[L])) {
        //         vowc[word[L]]++;
        //     } else {
        //         conso++;
        //     }
        //     if (conso == k && allVowelsPresent(vowc)) {
        //         ans += (!have.count({L,R}));
        //         debug(have.count({L,R}), have);
        //         have.insert({L,R});
        //     }
        //     L++;
        // }
        return ans;
    }
void dxt(int test_case){
	string s; int k;
	cin >> s >> k;

	cout << countOfSubstrings(s, k) << endl;
	
}















