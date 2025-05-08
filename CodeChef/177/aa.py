# /**
# *    created: 2025-03-12 21:19:44
# **/
# #include<bits/stdc++.h>
# using namespace std;
# #ifndef ONLINE_JUDGE
# #include "../debug.cpp"
# #else
# #define debug(...)
# #define debugArr(...)
# #endif
# #define int long long
# #define show(x) cout << x << endl
# #define sz(x) (int)(x.size())

# signed main(){
#     ios_base::sync_with_stdio(false); cin.tie(NULL);
#     auto solve_test = [&](int test_case){
#         int n;
#         cin >> n;
#         vector<int> ar(n);
#         int mx = 0;
#         for (int i = 0; i < n; i++){
#             cin >> ar[i];
#             mx = max(mx, ar[i]);
#         }
#         int bits = 0;
#         while((1LL << bits) <= mx) bits++;
#         if(bits == 0) bits = 1;
#         int size = 1LL << bits;
#         vector<long long> F(size, 0), dp(size, 0);
#         for (int i = 0; i < n; i++){
#             F[ar[i]]++;
#         }
#         for (int mask = 0; mask < size; mask++){
#             dp[mask] = F[mask];
#         }
#         for (int i = 0; i < bits; i++){
#             for (int mask = 0; mask < size; mask++){
#                 if(mask & (1LL << i))
#                     dp[mask] += dp[mask ^ (1LL << i)];
#             }
#         }
#         int P = 0;
#         int full = size - 1;
#         for (int mask = 0; mask < size; mask++){
#             P += F[mask] * dp[full ^ mask];
#         }
#         P /= 2;
#         long long tot = (long long)n * (n - 1);
#         cout << tot - P << "\n";

#     };
#     int T = 1;
#     cin >> T;
#     for(int i = 0; i < T; ++i){
#         solve_test(i);
#     }
# }
#convert this into python
import sys
import math 

def solve_test(test_case):
    n = int(input())
    ar = list(map(int, input().split()))
    mx = max(ar)
    bits = 0
    while (1 << bits) <= mx:
        bits += 1
    if bits == 0:
        bits = 1
    size = 1 << bits
    F = [0] * size
    dp = [0] * size
    for i in range(n):
        F[ar[i]] += 1
    for mask in range(size):
        dp[mask] = F[mask]
    for i in range(bits):
        for mask in range(size):
            if mask & (1 << i):
                dp[mask] += dp[mask ^ (1 << i)]
    P = 0
    full = size - 1
    for mask in range(size):
        P += F[mask] * dp[full ^ mask]
    P //= 2
    tot = n * (n - 1)
    print(tot - P)

T = 1
T = int(input())
for i in range(T):
    solve_test(i)