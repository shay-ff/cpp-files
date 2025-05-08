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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));
    vector<pair<ll, ll>> diff;
    ll i = 0;
    while(i < n){
        ll j = i + 1;
        while (j < n && a[j] == a[i]) j++;
        diff.push_back({a[i], j - i});
        i = j;
    }

    bool can = false;
    for (auto &p : diff) {
        if (p.second >= 4) {
            can = true;
            break;
        }
    }
    if (can) {
        cout << "Yes\n";
        return;
    }

    ll m = diff.size();
    i = 0;
    while(i < m) {
        ll cnt2 = (diff[i].second >= 2);
        ll j = i;
        while (j + 1 < m && diff[j + 1].first == diff[j].first + 1) {
            j++;
            if (diff[j].second >= 2)
                cnt2++;
        }
        if (cnt2 >= 2) {
            can = true;
            break;
        }
        i = j + 1;
    }

    if (can) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll test;
    cin >> test;
    while (test--) {
        hello();
    }
    return 0;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> answer;
        set<string> check(words.begin(),words.end());
        int n = board.size(), m = board[0].size();
        function<pair<bool,string>(int,int)> solve = [&](int i, int j) {
            string str;
            bool isThere = false;
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            queue<pair<int,int>> q;
            q.push({i,j});
            visited[i][j] = true;
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
                str += board[x][y];
                if(check.count(str)){
                    isThere = true;
                }
                for(int dx = -1; dx <= 1; ++dx){
                    for(int dy = -1; dy <= 1; ++dy){
                        if(abs(dx) == abs(dy)) continue;
                        int nx = x + dx, ny = y + dy;
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
                            visited[nx][ny] = true;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            return {isThere,str};
        };
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                auto [isThere, str] = solve(i,j);
                if(isThere){
                    answer.push_back(str);
                    check.erase(str);
                }
            }
        }
        return answer;
    }
};