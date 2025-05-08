/**
*    created: 2025-03-12 14:08:32
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

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto solve_test = [&](int test_case){
        
    };
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve_test(i);
    }
}

"Competitive Programming Template": {
        "prefix": "cp",
        "body": [
            "/**",
            "*    created: ${CURRENT_YEAR}-${CURRENT_MONTH}-${CURRENT_DATE} ${CURRENT_HOUR}:${CURRENT_MINUTE}:${CURRENT_SECOND}",
            "**/",
            "#include<bits/stdc++.h>",
            "using namespace std;",
            "",
            "#ifndef ONLINE_JUDGE",
            "#include \"../debug.cpp\"",
            "#else",
            "#define debug(...)",
            "#define debugArr(...)",
            "#endif",
            "",
            "#define int long long",
            "#define show(x) cout << x << endl",
            "#define sz(x) (int)(x.size())",
            "",
            "signed main(){",
            "    ios_base::sync_with_stdio(false); cin.tie(NULL);",
            "    auto solve_test = [&](int test_case){",
            "        $2",
            "    };",
            "    $1//int T = 1;",
            "    cin >> T;",
            "    for(int i = 0; i < T; ++i){",
            "        solve_test(i);",
            "    }",
            "}",
        ],
        "description": "Competitive programming C++ template"
    },