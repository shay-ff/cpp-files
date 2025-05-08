#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, k;
    cin >> m >> k;
  
    vector<vector<int>> pl(k, vector<int>(3));
    for (int i = 0; i < k; i++) {
        cin >> pl[i][0] >> pl[i][1] >> pl[i][2];
    }

    auto check = [&](int mid) {
        int _time = 0;
        vector<int> br(k, 0);
        for (int i = 0; i < k; i++) {
            int t = pl[i][0], z = pl[i][1], y = pl[i][2];
            int cycle_time = t * z + y;
            int full_cycles = mid / cycle_time;
            int remaining_time = mid % cycle_time;
            int items_in_remaining_time = min(remaining_time / t, z);
            int total_items = full_cycles * z + items_in_remaining_time;
            _time += total_items;
            br[i] = total_items;
        }
        if (_time >= m) {
            return make_pair(true, br);
        } else {
            return make_pair(false, br);
        }
    };

    int low = 0, high = 1e9, ans = -1;
    vector<int> final_br;

    while (low <= high) {
        int mid = (low + high) / 2;
        auto [is_possible, br] = check(mid);
        if (is_possible) {
            ans = mid;
            final_br = br;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    for (auto x : final_br) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
