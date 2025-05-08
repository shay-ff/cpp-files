/**
*    created: 2025-03-23 03:40:09
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

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int x,y;
        cin >> x >> y;

        if(x == y){
            show(-1);
            return;
        }
        if(x < y){
            swap(x, y);
        }
        int bits = 0, copy = x;
        while(copy){
            bits++;
            copy >>= 1;
        }
        auto numberToBinary = [](int n){
            string s = "";
            while(n){
                s += (n % 2) + '0';
                n >>= 1;
            }
            reverse(s.begin(), s.end());
            return s;
        };
        string xBinary = numberToBinary(x);
        string yBinary = numberToBinary(y);
        if(xBinary.size() < yBinary.size()){
            xBinary = string(yBinary.size() - xBinary.size(), '0') + xBinary;
        }
        else if(xBinary.size() > yBinary.size()){
            yBinary = string(xBinary.size() - yBinary.size(), '0') + yBinary;
        }
        string ansBinary = numberToBinary((1LL << bits) - x);
        show(xBinary);
        show(yBinary);
 
        if(ansBinary.size() < xBinary.size()){
            ansBinary = string(xBinary.size() - ansBinary.size(), '0') + ansBinary;
        }
        int a = 23 + 9, b = 23 & 9;
        debug(a,b);
        show(ansBinary);
        cout << (1LL << bits) - x << endl;
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}