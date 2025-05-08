/**
*    created: 2025-03-17 07:35:41
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// find_by_order(k) - returns an iterator to the k-th largest element (0 indexed)
// order_of_key(k) - Number of items strictly smaller than k
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class U> using ordered_pset = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// whats pset here?
// ordered_pset<int, int> pset;
// explain : https://codeforces.com/blog/entry/11080
/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

*/
/**
 * @file F_Variety_Split_Hard.cpp
 * @brief Implementation of the SORTracker class for tracking and retrieving elements in sorted order.
 */

/**
 * @class SORTracker
 * @brief A class to track and retrieve elements in a specific sorted order.
 * 
 * The SORTracker class maintains a set of pairs consisting of a score and a name.
 * It allows adding new elements and retrieving the next element in the sorted order.
 */
class SORTracker {
public:
    /**
     * @brief Constructor for SORTracker.
     * 
     * Initializes the iterator to the end of the set.
     */
    SORTracker();

    /**
     * @brief Adds a new element to the tracker.
     * 
     * @param name The name associated with the score.
     * @param score The score associated with the name.
     * 
     * Adds a pair of (-score, name) to the set and adjusts the iterator if necessary.
     */
    void add(string name, int score);

    /**
     * @brief Retrieves the next element in the sorted order.
     * 
     * @return The name associated with the next element in the sorted order.
     * 
     * Retrieves the name of the element pointed to by the iterator and advances the iterator.
     */
    string get();
    
private:
    set<pair<int, string>> s; 
    set<pair<int, string>>::iterator it; 
};
    }
    
    void add(string name, int score) {
        auto p = make_pair(-score, name);
        s.insert(p);
        if (it == s.end() || p < *it) {
            --it;
        }
    }
    
    string get() {
        string ans = it->second;
        ++it;
        return ans;
    }
};


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        Solution sol;
        int ans = sol.ladderLength("hit","cog",{"hot","dot","dog","lot","log","cog"});
        cout << ans << endl;
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}