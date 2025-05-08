/**
*    created: 2025-03-22 20:30:46
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
    
    auto solve_test = [&](int test_case) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<pair<int,int>> ans;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        
        int cntr = 0;
        for(auto &x : a){
            if(x == 0)
                cntr++;
        }
        if (a.size() > 1 && cntr == a.size()) {
            int sz = a.size();
            int m = 0;
            set<int> s;
            for (int i = sz - 2; i < sz; i++){
                s.insert(a[i]);
            }
            while (s.count(m)) m++;
            debug(sz - 1, sz, m);
            ans.push_back({sz - 1, sz});
            a.erase(a.begin() + sz - 2, a.end());
            a.push_back(m);
        }
        
        while (a.size() > 1 && find(a.begin(), a.end(), 0) != a.end()){
            int sz = a.size();
            int done = 0, beg = -1;
            {
                for (int i = 0; i < sz; i++){
                    if(a[i] == 0){
                        if(beg == -1)
                            beg = i;
                    }
                    else{
                        if(beg != -1 && (i - beg) >= 2){ 
                            int l = beg, r = i - 1;
                            int m = 0;
                            set<int> s;
                            for (int j = l; j <= r; j++){
                                s.insert(a[j]);
                            }
                            while(s.count(m)) m++;
                            debug(l, r, m);
                            ans.push_back({l + 1, r + 1});
                            a.erase(a.begin() + l, a.begin() + r + 1);
                            a.insert(a.begin() + l, m);
                            done = 1;
                            break;
                        }
                        beg = -1;
                    }
                }
                if(!done && beg != -1 && (sz - beg) >= 2){
                    int l = beg, r = sz - 1, m = 0;
                    set<int> s;
                    for (int j = l; j <= r; j++){
                        s.insert(a[j]);
                    }
                    while(s.count(m)) m++;
                    debug(l, r, m);
                    ans.push_back({l + 1, r + 1});
                    a.erase(a.begin() + l, a.end());
                    a.insert(a.begin() + l, m);
                    done = 1;
                }
            }
            
            if(!done){
                for (int i = 0; i < sz - 1; i++){
                    if(a[i] == 0 || a[i+1] == 0){
                        int l = i, r = i + 1;
                        int m = 0;
                        set<int> s;
                        for (int j = l; j <= r; j++){
                            s.insert(a[j]);
                        }
                        while(s.count(m)) m++;
                        debug(l, r, m);
                        ans.push_back({l + 1, r + 1});
                        a.erase(a.begin() + l, a.begin() + r + 1);
                        a.insert(a.begin() + l, m);
                        done = 1;
                        break;
                    }
                }
            }
            if(!done)
                break;
        }
        
        if(a.size() > 1){
            int sz = a.size();
            int m = 0;
            set<int> s;
            for (int i = 0; i < sz; i++){
                s.insert(a[i]);
            }
            while(s.count(m)) m++;
            debug(1, sz, m);
            ans.push_back({1, sz});
            a.clear();
            a.push_back(m);
        }
        
        show(ans.size());
        for(auto &[l, r] : ans)
            cout << l << " " << r << "\n";
    };
    
    int T = 1;
    cin >> T;
    for (int i = 0; i < T; i++){
        solve_test(i);
    }
    return 0;
}
