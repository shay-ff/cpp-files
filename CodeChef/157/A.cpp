#include <bits/stdc++.h>
using namespace std;

int find_median_position(vector<int>& arr, int left, int right) {
    vector<int> window(arr.begin() + left, arr.begin() + right + 1);
    vector<int> sorted_window = window;
    sort(sorted_window.begin(), sorted_window.end());
    int median_val = sorted_window[sorted_window.size() / 2];
    
    // Return leftmost occurrence
    for(int i = 0; i < window.size(); i++) {
        if(window[i] == median_val) {
            return left + i;
        }
    }
    return -1;
}

bool is_sorted_after_remove(const vector<int>& window, int pos) {
    vector<int> temp;
    for(int i = 0; i < window.size(); i++) {
        if(i != pos) temp.push_back(window[i]);
    }
    for(int i = 0; i < temp.size() - 1; i++) {
        if(temp[i] > temp[i + 1]) return false;
    }
    return true;
}

vector<pair<int,int>> solve_unmedian(vector<int>& A) {
    int N = A.size();
    vector<int> current = A;
    vector<pair<int,int>> operations;
    
    while(current.size() > 1) {
        bool found = false;
        for(int length = 3; length <= current.size() && !found; length += 2) {
            for(int start = 0; start + length <= current.size() && !found; start++) {
                int end = start + length;
                
                // Find median position
                int median_pos = find_median_position(current, start, end - 1);
                vector<int> window(current.begin() + start, current.begin() + end);
                
                if(is_sorted_after_remove(window, median_pos - start)) {
                    operations.emplace_back(start + 1, end); 
                    current.erase(current.begin() + median_pos);
                    found = true;
                }
            }
        }
        
        if(!found) return {};  
    
        bool is_sorted = true;
        for(int i = 0; i < current.size() - 1; i++) {
            if(current[i] > current[i + 1]) {
                is_sorted = false;
                break;
            }
        }
        if(is_sorted) break;
    }
    
    for(int i = 0; i < current.size() - 1; i++) {
        if(current[i] > current[i + 1]) return {};
    }
    
    return operations;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while(T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        auto operations = solve_unmedian(A);
        
        if(operations.empty()) {
            cout << "-1\n";
        } else {
            cout << operations.size() << "\n";
            for(const auto& [l, r] : operations) {
                cout << l << " " << r << "\n";
            }
        }
    }
    
    return 0;
}