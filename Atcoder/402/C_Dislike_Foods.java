#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // Read dishes
    vector<vector<int>> dishes(M);
    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;
        vector<int> ingreds(K);
        for (int j = 0; j < K; j++) {
            cin >> ingreds[j];
        }
        dishes[i] = ingreds;
    }

    // Read B and build inverse array D[j] = day when ingredient j is overcome
    vector<int> D(N + 1, 0);
    for (int day = 1; day <= N; day++) {
        int ing;
        cin >> ing;
        D[ing] = day;
    }

    // cnt[t] = how many dishes become edible exactly on day t
    vector<int> cnt(N + 1, 0);
    for (const auto& ingreds : dishes) {
        if (ingreds.empty()) {
            // no ingredients → edible from day 0
            cnt[0]++;
        } else {
            int t = 0;
            for (int ing : ingreds) {
                t = max(t, D[ing]);
            }
            cnt[t]++;
        }
    }

    // build answer by prefix‐summing cnt[]
    vector<int> ans(N + 1, 0);
    int running = cnt[0];
    for (int day = 1; day <= N; day++) {
        running += cnt[day];
        ans[day] = running;
    }

    // output days 1..N
    for (int day = 1; day <= N; day++) {
        cout << ans[day] << '\n';
    }

    return 0;
}
