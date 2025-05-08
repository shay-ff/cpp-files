#include <bits/stdc++.h>
using namespace std;

void dfs_fwd(int i, int j, int rem, int N, int M, const vector<vector<int>>& A, map<pair<int, int>, vector<int>>& fwd) {
    rem = (rem * 10 + A[i][j]) % M;
    if (i + j == N) {
        fwd[{i, j}].push_back(rem);
        return;
    }
    if (i + 1 < N) dfs_fwd(i + 1, j, rem, N, M, A, fwd);
    if (j + 1 < N) dfs_fwd(i, j + 1, rem, N, M, A, fwd);
}

void dfs_suf(int x, int y, int rem_suf, int depth, int N, int M, const vector<vector<int>>& A, vector<int>& suffix) {
    if (depth == N - 1) {
        suffix.push_back(rem_suf);
        return;
    }
    if (x + 1 < N) dfs_suf(x + 1, y, (rem_suf * 10 + A[x + 1][y]) % M, depth + 1, N, M, A, suffix);
    if (y + 1 < N) dfs_suf(x, y + 1, (rem_suf * 10 + A[x][y + 1]) % M, depth + 1, N, M, A, suffix);
}

int process_cell(int i, int j, const vector<int>& prefix_list, int N, int M, const vector<vector<int>>& A, int P10) {
    vector<int> suffix;
    dfs_suf(i, j, 0, 0, N, M, A, suffix);
    sort(suffix.begin(), suffix.end());

    int best = 0;
    int max_suf = suffix.back();
    for (int r_pref : prefix_list) {
        int shift = (r_pref * P10) % M;
        int t = M - shift;
        auto it = lower_bound(suffix.begin(), suffix.end(), t);
        if (it != suffix.begin()) {
            best = max(best, shift + *(--it));
        }
        if (shift + max_suf >= M) {
            best = max(best, shift + max_suf - M);
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    if (N == 1) {
        cout << A[0][0] % M << "\n";
        return 0;
    }

    int P10 = 1;
    for (int i = 0; i < N - 1; ++i) {
        P10 = (P10 * 10) % M;
    }

    map<pair<int, int>, vector<int>> fwd;
    dfs_fwd(0, 0, 0, N, M, A, fwd);

    int answer = 0;
    for (const auto& [cell, pre_list] : fwd) {
        int i = cell.first, j = cell.second;
        int ans_cell = process_cell(i, j, pre_list, N, M, A, P10);
        answer = max(answer, ans_cell);
    }

    cout << answer << "\n";
    return 0;
}
