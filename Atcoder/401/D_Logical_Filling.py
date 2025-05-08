#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // Backward DP
    vector<map<int, set<int>>> back(N + 1);
    back[N][0] = {0};
    back[N][1] = {0};

    for (int i = N - 1; i >= 0; --i) {
        back[i][0] = {};
        back[i][1] = {};
        for (int cur : {0, 1}) {
            // Option 1: Place a dot '.'
            if (S[i] == '.' || S[i] == '?') {
                for (int x : back[i + 1][0]) {
                    back[i][cur].insert(x);
                }
            }
            // Option 2: Place an 'o'
            if (cur == 0 && (S[i] == 'o' || S[i] == '?')) {
                for (int x : back[i + 1][1]) {
                    back[i][cur].insert(x + 1);
                }
            }
        }
    }

    // Forward DP
    vector<set<pair<int, int>>> possible(N + 1);
    possible[0].insert({0, 0});
    string result(N, '?');

    for (int i = 0; i < N; ++i) {
        bool can_dot = false, can_o = false;
        set<pair<int, int>> new_possible;

        for (auto [cnt, last] : possible[i]) {
            // Check possibility of placing a dot
            if (S[i] == '.' || S[i] == '?') {
                for (int add : back[i + 1][0]) {
                    if (cnt + add == K) {
                        can_dot = true;
                        break;
                    }
                }
            }
            // Check possibility of placing an 'o'
            if ((S[i] == 'o' || S[i] == '?') && last == 0 && cnt + 1 <= K) {
                for (int add : back[i + 1][1]) {
                    if (cnt + 1 + add == K) {
                        can_o = true;
                        break;
                    }
                }
            }
        }

        if (can_dot && !can_o) {
            result[i] = '.';
        } else if (can_o && !can_dot) {
            result[i] = 'o';
        } else {
            result[i] = '?';
        }

        for (auto [cnt, last] : possible[i]) {
            if (S[i] == '.' || S[i] == '?') {
                for (int add : back[i + 1][0]) {
                    if (cnt + add == K) {
                        new_possible.insert({cnt, 0});
                        break;
                    }
                }
            }
            if ((S[i] == 'o' || S[i] == '?') && last == 0 && cnt + 1 <= K) {
                for (int add : back[i + 1][1]) {
                    if (cnt + 1 + add == K) {
                        new_possible.insert({cnt + 1, 1});
                        break;
                    }
                }
            }
        }
        possible[i + 1] = new_possible;
    }

    if (possible[N].empty()) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
}

int main() {
    solve();
    return 0;
}
