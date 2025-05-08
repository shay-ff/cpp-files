#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    long long prev, nxt, steps=0, n;
    cin >> n >> prev;
    
    while(--n > 0)
    {
        cin >> nxt;
        
        if( prev > nxt)
        steps += prev - nxt;
        
        else 
        prev = nxt;
        
    }
    cout << steps << endl;
    return 0;
}