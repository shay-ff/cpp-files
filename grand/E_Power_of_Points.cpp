/**
*    created: 2025-03-13 03:44:05
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
/*
You are given n points with integer coordinates x1,…xn, which lie on a number line.

For some integer s, we construct segments [s,x1], [s,x2], …, [s,xn]. Note that if xi<s, then the 
segment will look like [xi,s]. The segment [a,b] covers all integer points a,a+1,a+2,…,b.

We define the power of a point p as the number of segments that intersect the point with coordinate p, denoted as fp.

Your task is to compute ∑p=1^109 fp for each s∈{x1,…,xn}, i.e., the sum of fp for all integer points from 1 to 109.

For example, if the initial coordinates are [1,2,5,7,1] and we choose s=5, then the segments will be: [1,5],[2,5],[5,5],[5,7],[1,5]. 
And the powers of the points will be: f1=2,f2=3,f3=3,f4=3,f5=5,f6=1,f7=1,f8=0,…,f109=0. Their sum is 2+3+3+3+5+1+1=18.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    auto solve_test = [&](int test_case){
        int N;
        cin >> N;
        vector<int> A(N);
        for(auto &x : A)
            cin >> x;
        vector<int> order(N, 0);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j){
            return A[i] < A[j];
        });
        sort(A.begin(), A.end());
        vector<int> ans(N, 0);
        vector<int> prefix_sum(N + 1, 0);
        for(int i = 0; i < N; ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + A[i];
        }
        
        for(int i = 0; i < N; ++i) {
            int left_sum = A[i] * i - prefix_sum[i];
            int right_sum = (prefix_sum[N] - prefix_sum[i + 1]) - A[i] * (N - i - 1);
            ans[order[i]] = left_sum + right_sum + N;
        }
        for(auto x : ans)
            cout << x << " ";
        cout << endl;
        

    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}