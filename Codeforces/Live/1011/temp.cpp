#include <bits/stdc++.h>
using namespace std;

int mex(const vector<int>& a, int l, int r) {
    int len = r - l + 1;
    vector<bool> present(len+3, false);
    for (int i = l; i <= r; i++){
        int x = a[i];
        if(x < (int)present.size())
            present[x] = true;
    }
    int m = 0;
    while(m < (int)present.size() && present[m])
        m++;
    return m;
}

bool hasZero(const vector<int>& a) {
    for (int x : a)
        if(x == 0)
            return true;
    return false;
}

bool allZero(const vector<int>& a) {
    for (int x : a)
        if(x != 0)
            return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<pair<int,int>> ops;

        if(a.size() > 1 && allZero(a)){
            int sz = a.size();
            int m = mex(a, sz-2, sz-1);
            ops.push_back({sz-1, sz});
            a.erase(a.begin() + sz - 2, a.end());
            a.push_back(m);
        }

        while(a.size() > 1 && hasZero(a)){
            int sz = a.size();
            bool performed = false;
            {
                int start = -1;
                for (int i = 0; i < sz; i++){
                    if(a[i] == 0){
                        if(start == -1) 
                            start = i;
                    } else {
                        if(start != -1 && i - start >= 2){
                            int l = start, r = i - 1;
                            int m = mex(a, l, r);
                            ops.push_back({l+1, r+1});
                            a.erase(a.begin() + l, a.begin() + r + 1);
                            a.insert(a.begin() + l, m);
                            performed = true;
                            break;
                        }
                        start = -1;
                    }
                }
                if(!performed && start != -1 && sz - start >= 2){
                    int l = start, r = sz - 1;
                    int m = mex(a, l, r);
                    ops.push_back({l+1, r+1});
                    a.erase(a.begin() + l, a.end());
                    a.insert(a.begin() + l, m);
                    performed = true;
                }
            }
            if(performed)
                continue;

            for (int i = 0; i < sz - 1; i++){
                if(a[i] == 0 || a[i+1] == 0){
                    int l = i, r = i+1;
                    int m = mex(a, l, r);
                    ops.push_back({l+1, r+1});
                    a.erase(a.begin() + l, a.begin() + r + 1);
                    a.insert(a.begin() + l, m);
                    performed = true;
                    break;
                }
            }
            if(!performed) break;
        }

        if(a.size() > 1){
            int sz = a.size();
            int m = mex(a, 0, sz - 1);
            ops.push_back({1, sz});
            a.clear();
            a.push_back(m);
        }
        cout << ops.size() << "\n";
        for(auto &p : ops)
            cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
