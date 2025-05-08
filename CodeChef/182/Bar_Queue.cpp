/**
*    created: 2025-04-16 20:00:24
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
Bar Queue
Chef is throwing a grand party at a bar. There is already a queue at the entrance, waiting for the event to start.

The queue can be represented as a string 
S
S consisting of 
N
N characters, each either 'B' (representing a boy) or 'G' (representing a girl).

The first character of the string represents the front of the queue. The entrance gate security allows people to enter one by one from the front of the queue, but as soon as the number of boys who have already entered the bar exceeds twice the number of girls, the security closes the entrance.

You have to determine the number of people in the queue who were allowed to enter the bar.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains one integer 
N
N — the length of 
S
S.
The next line contains the binary string 
S
S.
*/
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        int n; string s;
        cin >> n >> s;
        int b = 0, g = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == 'B') b++;
            else g++;
            if(b > 2 * g) {
                cout << i + 1 << endl;
                return;
            }
        }
        cout << n << endl;
    };
    int T = 1;
    cin >> T;   
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}