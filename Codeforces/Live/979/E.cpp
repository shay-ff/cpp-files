#include <bits/stdc++.h>
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

using ll = long long int;
const int naxn = 500500;



void dxt() {
    int n;
    cin >> n;

    string str = "1";
    auto ask = [&](int l, int r){
        cout << "? " << l << " " << r << endl;
        cout.flush();
        int t;
        cin >> t;
        return t;
    };
    bool ok = true;
    int cntr = 0;
    string ptr = "0";
    for(int i = 1; i < n; ++i){
        int x = ask(i, i + 1);
        if(i == 1 && x){
            if(str.back() == '1'){
                str.back() = '0';
            }
        }
        cntr += x;
        if(x > 1){
            ok = false;
        }
        if(x != 1){
            str += '0';
            ptr += '1';
        }
        else{
            str += '1';
            ptr += '1';
        }
    }
    debug(str, ptr);
    if((str != ptr)){
        cout << "! " << "IMPOSSIBLE" << endl;
    }
    else{
        cout <<"! ";
        cout << str << endl;
    }
    // // debug(ptr);
    // cout << "! " << str << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        dxt();
    }
}
