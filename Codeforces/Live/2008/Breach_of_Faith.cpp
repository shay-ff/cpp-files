#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> b(2 * n);
        for (int i = 0; i < 2 * n; i++){
            cin >> b[i];
        }
        sort(b.begin(), b.end());
 
        // Default partition: M = first n elements, P = last n elements.
        long long sumM = 0, sumP = 0;
        for (int i = 0; i < n; i++) {
            sumM += b[i];
        }
        for (int i = n; i < 2 * n; i++){
            sumP += b[i];
        }
        long long defaultX = sumP - sumM;
 
        // For fast membership check (we need x not to be in b)
        set<long long> bset;
        for (auto &x : b)
            bset.insert(x);
 
        // We plan to output the sequence a as:
        // a1 = x, and then a2 = P[0], a3 = M[0], a4 = P[1], a5 = M[1], ..., a_{2n} = P[n-1], a_{2n+1} = M[n-1]
        auto outputSequence = [&](long long x, const vector<long long>& P, const vector<long long>& M) {
            cout << x;
            for (int i = 0; i < n; i++){
                cout << " " << P[i] << " " << M[i];
            }
            cout << "\n";
        };
 
        // If the default x is positive and not in b, use the default partition.
        if(defaultX > 0 && bset.find(defaultX) == bset.end()){
            vector<long long> P(b.begin() + n, b.end());
            vector<long long> M(b.begin(), b.begin() + n);
            outputSequence(defaultX, P, M);
            continue;
        }
 
        // Otherwise, try to fix the partition by swapping one element from M with one from P.
        // We'll try candidate indices near the boundary.
        bool found = false;
        long long candidateX = -1;
        // Copy default groups (they are in sorted order)
        vector<long long> P(b.begin() + n, b.end());
        vector<long long> M(b.begin(), b.begin() + n);
 
        // We'll search over a limited window.
        int L = min(n, 300);
        // When n < L, the loop still covers the whole groups.
        for (int i = n - L; i < n && !found; i++){
            for (int j = n; j < n + L && !found; j++){
                // Effect of swapping M[i] (which is b[i]) and P[j - n] (which is b[j]):
                // New difference: newX = defaultX - 2*(b[j] - b[i])
                long long newX = defaultX - 2LL * (b[j] - b[i]);
                if(newX > 0 && bset.find(newX) == bset.end()){
                    candidateX = newX;
                    // Perform the swap in our copies of the groups.
                    long long tmp = M[i];
                    M[i] = b[j];
                    P[j - n] = tmp;
                    found = true;
                }
            }
        }
 
        // In the unlikely event no candidate was found in the limited window, do a full search.
        if(!found){
            for (int i = 0; i < n && !found; i++){
                for (int j = n; j < 2 * n && !found; j++){
                    long long newX = defaultX - 2LL * (b[j] - b[i]);
                    if(newX > 0 && bset.find(newX) == bset.end()){
                        candidateX = newX;
                        vector<long long> M_copy(b.begin(), b.begin() + n);
                        vector<long long> P_copy(b.begin() + n, b.end());
                        long long tmp = M_copy[i];
                        M_copy[i] = b[j];
                        P_copy[j - n] = tmp;
                        M = move(M_copy);
                        P = move(P_copy);
                        found = true;
                    }
                }
            }
        }
 
        // According to the problem guarantee, we must have found a valid partition.
        if(found){
            outputSequence(candidateX, P, M);
        } else {
            // fallback (should not happen): output default partition (even if duplicate)
            outputSequence(defaultX, vector<long long>(b.begin() + n, b.end()),
                                  vector<long long>(b.begin(), b.begin() + n));
        }
    }
    return 0;
}
