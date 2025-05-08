/**
*    created: 2025-03-15 17:30:28
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
Takahashi measured his body temperature and found it to be 
X 
∘
 C.

Body temperature is classified into the following:

Higher than or equal to 
38.0 
∘
 C: “High fever”
Higher than or equal to 
37.5 
∘
 C and lower than 
38.0 
∘
 C: “Fever”
Lower than 
37.5 
∘
 C: “Normal”
Which classification does Takahashi's body temperature fall into? Present the answer as an integer according to the Output section.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        double x;
        cin >> x;
        if(x >= 38){
            cout << 1 << endl;
        }else if(x >= 37.5 && x < 38){
            cout << 2 << endl;
        }else{
            cout << 3 << endl;
        }
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}