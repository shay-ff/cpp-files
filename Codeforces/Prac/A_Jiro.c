/*
There are three brothers named A, B, and C. The age relationships among them are given by three characters 
S 
AB
​
 ,S 
AC
​
 ,S 
BC
​
 , which mean the following:

If 
S 
AB
​
  is <, then 
A is younger than 
B; if it is >, then 
A is older than 
B.
If 
S 
AC
​
  is <, then 
A is younger than 
C; if it is >, then 
A is older than 
C.
If 
S 
BC
​
  is <, then 
B is younger than 
C; if it is >, then 
B is older than 
C.
Who is the middle brother, that is, the second oldest among the three?
*/
#include <bits/stdc++.h>
using namespace std;
void dxt(int test_case){
    string s;
    cin >> s;
    if(s[1] == '<'){
        swap(s[0], s[2]);
    }
    if(s[3] == '<'){
        swap(s[2], s[4]);
    }
    if(s[1] == '<'){
        swap(s[0], s[2]);
    }
    if(s[1] == '>'){
        cout << s[2] << s[0] << s[4] << endl;
    }else{
        cout << s[0] << s[2] << s[4] << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        dxt(i);
    }
    return 0;
}