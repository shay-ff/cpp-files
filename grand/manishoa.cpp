#include <bits/stdc++.h>
using namespace std;

bool canRep(int x,  vector<int>& avail, map<int, int>& freq) {
    for (int a : avail) {
        int b = x - a;
        if(b == a) {
            if(freq.at(a) >= 2)
                return true;
        } else {
            if(freq.find(b) != freq.end())
                return true;
        }
    }
    return false;
}

int Min_budget(int n, vector<int> arr){
    int ans = 0;
    vector<int> temp;
    map<int, int> cnt;
    
    for (int i = 0; i < n; i++){
        int x = arr[i];
        if (temp.empty() || !canRep(x, temp, cnt)) {
            ans++;
        }
        temp.push_back(x);
        cnt[x]++; 
    }
    
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int ans = Min_budget(n, arr);
    cout << ans << endl;
    return 0;
}
