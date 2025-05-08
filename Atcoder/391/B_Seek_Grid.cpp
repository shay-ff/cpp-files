#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353


/*

You are given an 
N×N grid 
S and an 
M×M grid 
T. The cell at the 
i-th row from the top and the 
j-th column from the left is denoted by 
(i,j).

The colors of the cells in 
S and 
T are represented by 
N 
2
  characters 
S 
i,j
​
  (
1≤i,j≤N) and 
M 
2
  characters 
T 
i,j
​
  (
1≤i,j≤M), respectively. In grid 
S, cell 
(i,j) is white if 
S 
i,j
​
  is ., and black if 
S 
i,j
​
  is #. The same applies for grid 
T.

Find 
T within 
S. More precisely, output integers 
a and 
b (
1≤a,b≤N−M+1) that satisfy the following condition:

S 
a+i−1,b+j−1
​
 =T 
i,j
​
  for every 
i,j (
1≤i,j≤M).
*/
void dxt(int test_case){
	int n,m;
	cin >> n >> m;

	vector<vector<char>> S(n, vector<char> (n)), T(m, vector<char> (m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> S[i][j];
		}
	}
	for(int j = 0; j < m; ++j){
		for(int i = 0; i < m; ++i){
			cin >> T[j][i];
		}
	}
    int a,b;
    for(int i = 0; i <= n - m; ++i){
        for(int j = 0; j <= n - m; ++j){
            bool ok = true;
            for(int x = 0; x < m; ++x){
                for(int y = 0; y < m; ++y){
                    if(S[i + x][j + y] != T[x][y]){
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(ok){
                a = i + 1;
                b = j + 1;
                break;
            }
        }
        if(a) break;
    }
    cout << a << " " << b << '\n';

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	// cin >> T;
	for (int i = 1; i <= T; i++) {
	    dxt(i);
	}
	return 0;
}




/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 
*/
class Solution {
public:
    int maxDistance(string s, int k) {
        map<char,pair<int,int>> mp;
        mp['N'] = {0,1};
        mp['S'] = {0, -1};
        mp['E'] = {1, 0};
        mp['W'] = {-1, 0};
        auto solve = [&](string &s, int t){
            int x = mp[s[0]].first, y = mp[s[0]].second;
            int ans = -10000000;
            auto opp = [&](char x){
                if(x == 'S') return 'N';
                else if(x == 'N') return 'S';
                else if(x == 'E') return 'W';
                else return 'E';
            };
            set<char> happened;
            happened.insert(s[0]);
            ans = max(ans, abs(x) + abs(y));
            for(int i = 1; i < s.size(); ++i){
                char t = opp(s[i]);
                if(happened.count(opp(s[i])) && k){
                    k--;
                    if(s[i] == 'S') x += mp['N'].first, y += mp['N'].second;
                    if(s[i] == 'N') x += mp['S'].first, y += mp['S'].second;
                    if(s[i] == 'W') x += mp['E'].first, y += mp['E'].second;
                    if(s[i] == 'E') x += mp['W'].first, y += mp['W'].second;
                    s[i] = t;
                }
                else{
                    happened.insert(s[i]);
                    x += mp[s[i]].first;
                    y += mp[s[i]].second;
                }
                cout << x << " " << y << endl;
                ans = max(ans, abs(x) + abs(y));
            };
            return ans;
        }
        int fans = -100000;
        string dir = "SNWE";
        // erase s[0] from dir
        dir.erase(dir.find(s[0]), 1);
        // explain the 1 here
        fans = max(fans, solve(s, k - 1));
        string t = s;
        for(auto x : dir){
            s = t;
            s[0] = x;
            fans = max(fans, solve(s, k - 1));
        }
        
        return fans;
    }
};