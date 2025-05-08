/**
*    created: 2025-04-08 20:32:16
**/
#include <bits/stdc++.h>
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


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    auto solve_test = [&](int test_case){
        int n, q;
        cin >> n >> q;
        
        string in = "->", out = "<-";
        
        function<int(int,int,int)> get = [&](int n, int x, int y) -> int {
            if(n == 1){
                int i = x - 1, j = y - 1;
                int ar[2][2] = { {1, 4}, {3, 2} };
                return ar[i][j];
            }
            int m = 1 << (n - 1), tot = m * m;

            if(x <= m && y <= m){
                return get(n - 1, x, y); 
            }
            else if(x > m && y > m){
                return tot + get(n - 1, x - m, y - m);
            }
            else if(x > m && y <= m){
                return 2 * tot + get(n - 1, x - m, y);
            }
            else{
                return 3 * tot + get(n - 1, x, y - m);
            }
        };
        
        function<pair<int,int>(int,int,int)> get2 = [&](int n, int d, int m) -> pair<int,int>{
            if(n == 1){
                int ar[2][2] = { {1, 4}, {3, 2} };
                for(int i = 0; i < 2; ++i){
                    for(int j = 0; j < 2; ++j){
                        if(ar[i][j] == d + 1){
                            return {i + 1, j + 1};
                        }
                    }
                }
            }
            int tot = m * m;
            if(d < tot){
                return get2(n - 1, d, m / 2);
            }
            else if(d < 2 * tot){
                auto [x, y] = get2(n - 1, d - tot, m / 2);
                return {x + m, y + m};
            }
            else if(d < 3 * tot){
                auto [x, y] = get2(n - 1, d - 2 * tot, m / 2);
                return {x + m, y};
            }
            else{
                auto [x, y] = get2(n - 1, d - 3 * tot, m / 2);
                return {x, y + m};
            }
        };
        
        for(int i = 0; i < q; ++i){
            string s;
            cin >> s;
            if(s == in){
                int x, y;
                cin >> x >> y;
                cout << get(n, x, y) << "\n";
            }
            else{
                int p;
                cin >> p;
                int m = 1 << (n - 1);
                if(p > 4 * m * m){
                    cout << "0\n";
                }
                else{
                    auto [x, y] = get2(n, p - 1, m);
                    cout << x << " " << y << "\n";
                }
            }
        }
    };
    
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
    return 0;
}
