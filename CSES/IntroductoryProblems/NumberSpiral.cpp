#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
    ll x,y;
    cin >> x >> y;
    
    if(x<=y){
    	if(y%2==0){
    		cout << (y-1)*(y-1) + x <<"\n";
    	}
    	else
    		cout << y*y -(x-1) <<"\n";
    }
    else{
    	if(x%2==0){
    		cout << x*x - (y-1) <<"\n";
    	}
    	else
    		cout << (x-1)*(x-1) + y <<"\n";
    }
    
    
}
 
int32_t main()
 
{
 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll tt;
    cin >> tt;
     while(tt--)
     {
        solve();
        
     }
 
    return 0;
}