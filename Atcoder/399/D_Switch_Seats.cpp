#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// A structure to represent an eligible pair (adjacent positions that are not originally together)
struct EligiblePair {
    int pos; // starting index of the eligible pair in the seating arrangement
    int x, y; // the two values (couple labels)
};

// A hash function for a pair of integers (to be used as key in unordered_map)
struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        // combine the two integers into one hash value
        return ((size_t)p.first << 32) ^ (unsigned int)p.second;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
    cin >> n;
    int size = 2 * n;
    vector<int> a(size);
    for (int i = 0; i < size; i++){
        cin >> a[i];
    }
    
    // Collect all eligible pairs (i, i+1) where a[i] != a[i+1]
    vector<EligiblePair> eligible;
    for (int i = 0; i < size - 1; i++){
        if(a[i] != a[i+1]){
            eligible.push_back({i, a[i], a[i+1]});
        }
    }
    
    // For each eligible pair type (x,y), store the starting indices (pos) in a map.
    unordered_map<pair<int,int>, vector<int>, PairHash> mp;
    for (const auto &p : eligible){
        mp[{p.x, p.y}].push_back(p.pos);
    }
    
    // Sort the index vectors for each pair type so that binary search can be used.
    for (auto &entry : mp) {
        sort(entry.second.begin(), entry.second.end());
    }
    
    long long count = 0;
    // For each eligible pair (with type (x,y) at position pos), count how many eligible pairs of type (y,x)
    // occur with starting index at least pos + 2.
    for (const auto &p : eligible) {
        pair<int,int> revPair = {p.y, p.x};
        if (mp.find(revPair) != mp.end()){
            const vector<int> &indices = mp[revPair];
            // We need indices j such that j >= p.pos + 2.
            auto it = lower_bound(indices.begin(), indices.end(), p.pos + 2);
            count += indices.end() - it;
        }
    }
    
    cout << count << "\n";
    }
    return 0;
}
