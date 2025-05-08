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
/*
Kevin is trapped in Lakeside Village by Grace. At the exit of the village, there is a combination lock that can only be unlocked if Kevin solves it.

The combination lock starts with an integer 𝑥
. Kevin can perform one of the following two operations zero or more times:

If 𝑥≠33
, he can select two consecutive digits 3
 from 𝑥
 and remove them simultaneously. For example, if 𝑥=13323
, he can remove the second and third 3
, changing 𝑥
 to 123
.
If 𝑥≥33
, he can change 𝑥
 to 𝑥−33
. For example, if 𝑥=99
, he can choose this operation to change 𝑥
 to 99−33=66
.
When the value of 𝑥
 on the combination lock becomes 0
, Kevin can unlock the lock and escape from Lakeside Village. Please determine whether it is possible for Kevin to unlock the combination lock and escape.
*/
void pre_pro(){
}
void dxt(int test_case){
    int n;
    cin >> n;

    if(n % 33 == 0){
        cout << "YES\n";
        return;
    }
    auto check = [&](string &s){

    };
    if(n < 33){
        cout << "NO\n";
        return;
    }
    
    string s = to_string(n);
    for(int i = 0; i < sz(s); i++){
        if(s[i] == '3' and i + 1 < sz(s) and s[i + 1] == '3'){
            string temp = s.substr(0, i) + s.substr(i + 2);
            if(temp == "0" or stoi(temp) % 33 == 0){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";


}