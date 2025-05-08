#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long

template <class T>
T cubrt(T n) {
    T lo = 0, hi = n;
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        if (mid * mid * mid <= n)
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

template <class T>
T isqrt(T X) {
    T low = 0, high = 10000000000LL;
    while (low <= high) {
        T mid = (low + high) / 2;
        __int128 sq = ( __int128 ) mid * mid;
        if (sq == X)
            return mid;
        else if (sq < X)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    bool found = false;

    for (int x = 1; x <= 1000000; x++) {
        if (n % x != 0) 
            continue;
        int M = n / x;
        if (x * x > 4LL * M) 
            continue;
        
        unsigned long long deter = 3ULL * (4ULL * M - x * x);
        
        long long p = isqrt(deter);
        if ((unsigned long long)p * p != deter) 
            continue;
        
        if ((p - 3 * x) % 6 != 0) 
            continue;
        
        int y = (p - 3 * x) / 6;
        if (y <= 0) 
            continue;
        
        cout << (y + x) << " " << y << "\n";
        found = true;
        break;
    }
    
    if (!found) 
        cout << -1 << "\n";
    
    return 0;
}
