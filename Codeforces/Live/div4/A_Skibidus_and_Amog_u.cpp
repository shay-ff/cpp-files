#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353

template<typename T> using MaxHeap = std::priority_queue<T>;
template<typename T> using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
void dxt(int test_case){
    int n, d;
    cin >> n >> d;
    vector<int> ar(n);
    for(auto &x : ar){
        cin >> x;
    }
    int total_chocolates = accumulate(ar.begin(),ar.end(), 0LL);
    priority_queue<int> pq;
    for(auto &x : ar){
        pq.push(x);
    }
    int eaten = 0;
    while(d--){
        auto curr = pq.top();
        pq.pop();
        eaten += curr/2;
        if(curr & 1){
            curr/=2;
            curr++;
        }
        else curr/=2;
        pq.push(curr);
    }
    cout << total_chocolates - eaten << endl;
    
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        dxt(i);
    }
    return 0;
}




/*
 A little voice in my head said : "I couldn't do it!"
 So I practiced and practiced and guess what?
 That little voice ... was right! 
*/
