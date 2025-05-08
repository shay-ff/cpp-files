#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  string s;
  cin >> s;
  
  int cntr = 0;
  for(int i = 0; i < s.size(); ++i){
    cntr += (s[i] == '(' ? 1 : -1);
    if(cntr < 0){
      if(i == 0){
        s.insert(s.begin(), '(');
      }
      else{
        s.insert(s.begin() + i, '(');
      }
    }
    // cout << i << " " << cntr << endl;
  }
  // cout << cntr << endl;
  while(cntr--){
  	s += ')';
  }
  cout << s << endl;

}