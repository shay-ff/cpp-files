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

const int naxn = 1e6 + 10;
bool is_prime[naxn];
void findPrimes(){
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= naxn; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= naxn; j += i)
                is_prime[j] = false;
        }
    }
}

void dxt(int test_case){
    int n;
    cin >> n;
    
    // Using multiset for maintaining sorted order
    multiset<int> numbers;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numbers.insert(x);
    }
    
    int uniqueCount = 0;
    
    // Continue until collection is empty
    while(!numbers.empty()) {
        // Get maximum element
        auto it = numbers.end();
        --it;  // Now points to maximum element
        int maxNum = *it;
        
        // Count occurrences of maximum element
        int count = numbers.count(maxNum);
        
        // Remove all instances of maximum element
        numbers.erase(maxNum);
        
        // If maximum was unique
        if(count == 1) {
            uniqueCount++;
            // Add half if it's >= 2
            if(maxNum >= 2) {
                numbers.insert(maxNum / 2);
            }
        }
        
        // Debug output to see the process
        cout << "Current max: " << maxNum << ", count: " << count << ", inseted : " << maxNum/2 << " ";
        cout << ", unique count: " << uniqueCount << ", set: ";
        for(int x : numbers) cout << x << " ";
        cout << endl;
    }
    
    cout << uniqueCount << endl;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    findPrimes();
    cin >> T;
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
