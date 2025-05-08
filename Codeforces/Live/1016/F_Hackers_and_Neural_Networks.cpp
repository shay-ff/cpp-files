/**
*    created: 2025-04-08 21:55:22
**/
#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())

struct TrieNode {
    int cntr;
    TrieNode* children[2];
    TrieNode(): cntr(0) {
        children[0] = children[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* node = root;
        node->cntr++;
        for (int i = 0; i <= 31; i++) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) node->children[bit] = new TrieNode();
            node = node->children[bit];
            node->cntr++;
        }
    }
    
    void remove(int num) {
        TrieNode* node = root;
        node->cntr--;
        for (int i = 0; i <= 31; i++) {
            int bit = (num >> i) & 1;
            node = node->children[bit];
            node->cntr--;
        }
    }
    
    int query(int num) {
        TrieNode* node = root;
        int ans = 0;
        for (int i = 0; i <= 31; i++) {
            int bit = (num >> i) & 1;
            if (node->children[1-bit] && node->children[1-bit]->cntr > 0) {
                ans |= (1 << i);
                node = node->children[1-bit];
            } else {
                node = node->children[bit];
            }
        }
        return ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        if(k == 0){
            cout << 1 << endl;
            return;
        }
        auto can = [&](int mid){
            Trie trie;
            for (int i = 0; i < mid; i++) {
                trie.insert(a[i]);
            }
            int bxor = 0;
            for (int i = 0; i < mid; i++) {
                bxor = max(bxor, trie.query(a[i]));
            }
            if (bxor >= k){
                return true;
            }
            for (int i = mid; i < sz(a); i++) {
                trie.remove(a[i-mid]);
                trie.insert(a[i]);
                bxor = 0;
                for (int j = i - mid + 1; j <= i; j++) {
                    bxor = max(bxor, trie.query(a[j]));
                }
                if (bxor >= k) return true;
            }
            return false;
        }
        int low = 2, high = n, ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(can(mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        show(ans);
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}