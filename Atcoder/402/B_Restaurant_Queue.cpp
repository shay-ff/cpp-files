/**
*    created: 2025-04-19 17:30:50
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
Takahashi wants to manage the waiting line in front of the AtCoder Restaurant. Initially, the waiting line is empty. Each person who joins the line holds a meal ticket with the menu number of the dish they will order.

Process 
Q queries in order. There are two types of queries, given in the following formats:

1 X: One person joins the end of the waiting line holding a ticket with menu number 
X.
2: Takahashi guides the person at the front of the waiting line into the restaurant. Print the menu number on that person’s ticket.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int q;
        cin >> q;

        queue<int> q1;
        while(q--){
            int t;
            cin >> t;
            if(t == 1){
                int x;
                cin >> x;
                q1.push(x);
            }else{
                cout << q1.front() << endl;
                q1.pop();
            }
        }
        
    };
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}