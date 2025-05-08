#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int int64_t
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
typedef long double lld;
using ull = unsigned long long;
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353
/* "So do not lose heart nor fall into despair, for you will be superior if you are true in faith!" */
template <class T> bool setmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template <class T> bool setmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}

void dxt(int test_case);
void pre_pro();
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	pre_pro();
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
	    dxt(i);
	}
	return 0;
}

void pre_pro(){
}
/*
You are given three non-negative integers 𝑏
, 𝑐
, and 𝑑
.

Please find a non-negative integer 𝑎∈[0,261]
 such that (𝑎|𝑏)−(𝑎&𝑐)=𝑑
, where |
 and &
 denote the bitwise OR operation and the bitwise AND operation, respectively.

If such an 𝑎
 exists, print its value. If there is no solution, print a single integer −1
. If there are multiple solutions, print any of them.
*/
void dxt(int test_case){
	int b,c,d;
	cin >> b >> c >> d;

	int a = 0, can = 1;

	for(int i = 62; i >= 0; --i){
		int bb = (b >> i) & 1, cc = (c >> i) & 1, dd = (d >> i) & 1;
        if(dd){
            if(!bb){
                if(cc){
                    can = 0;
                    break;
                }
                else{
                    a |= (1LL << i);
                }
            }
        }
        else{
            if(bb){
                if(cc)
                    a |= (1LL << i);
                else{
                    can = 0;
                    break;
                }
            }
        }
	}
	cout << (can ? a : -1) << endl;
	
}