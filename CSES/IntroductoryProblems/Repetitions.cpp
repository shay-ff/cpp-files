/******************************************************************************
 
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
 
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    char current;
    int count = 0, answer = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != current) {
            current = s[i];
            count = 0;
        }
        if (s[i] == current) {
            count++;
        }
        answer = max(answer, count);
    }
    cout << answer;
}