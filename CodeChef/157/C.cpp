#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int int64_t
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define rrep(i, a, b) for(int i = a; i >= b; --i)
 
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

template <class T> bool setmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template <class T> bool setmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}

void dxt(int test_case);
void pre_pro();
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	pre_pro();
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
	    dxt(i);
	}
	return 0;
}

void pre_pro(){
}
int helper(vector<int>& arr, int left, int right) {
    vector<int> temp(arr.begin() + left, arr.begin() + right + 1);
    vector<int> br = temp;
    sort(br.begin(), br.end());
    int median_val = br[br.size() / 2];
    
    for(int i = 0; i < temp.size(); i++) {
        if(temp[i] == median_val) {
            return left + i;
        }
    }
    return -1;
}

bool check( vector<int>& ar, int pos) {
    vector<int> temp;
    for(int i = 0; i < ar.size(); i++) {
        if(i != pos) temp.push_back(ar[i]);
    }
    for(int i = 0; i < temp.size() - 1; i++) {
        if(temp[i] > temp[i + 1]) return false;
    }
    return true;
}
vector<pair<int,int>> solve(vector<int>& A) {
    int n = A.size();
    vector<int> curr = A;
    vector<pair<int,int>> oprt;
    
    while(curr.size() > 1) {
        bool have = false;
        for(int i = 3; i <= curr.size() && !have; i += 2) {
            for(int j = 0; j + i <= curr.size() && !have; j++) {
                int end = j + i;
                
                int mpos = helper(curr, j, end - 1);
                vector<int> temp(curr.begin() + j, curr.begin() + end);
                
                if(check(temp, mpos - j)) {
                    oprt.emplace_back(j + 1, end); 
                    curr.erase(curr.begin() + mpos);
                    have = true;
                }
            }
        }
        
        if(!have) return {};  
    
        bool is_sorted = true;
        for(int i = 0; i < curr.size() - 1; i++) {
            if(curr[i] > curr[i + 1]) {
                is_sorted = false;
                break;
            }
        }
        if(is_sorted) break;
    }
    
    for(int i = 0; i < curr.size() - 1; i++) {
        if(curr[i] > curr[i + 1]) return {};
    }
    
    return oprt;
}

void dxt(int test_case){
	int n; cin >> n;
	vector<int> ar(n);
	rep(i, 0, n){
		cin >> ar[i];
	}
	auto ans = solve(ar);
        
    if(ans.empty()) {
        cout << "-1\n";
    } 
    else {
        cout << ans.size() << "\n";
        for(auto &[l, r] : ans) {
            cout << l << " " << r << "\n";
        }
    }

}















/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 

*/







