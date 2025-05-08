/******************************************************************************
 
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
 
*******************************************************************************/
#include <iostream>
 
using namespace std;
 
int main()
{
    long long int n, sum=0, a;
    cin >> n;
    for ( int i=0; i<n-1; i++)
    {
        cin >>a;
        sum = sum+a;
    }
    cout << n * (n+1) / 2 - sum;
 
    return 0;
}