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
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
const int N = 200200, INF = 8e18, MOD = 1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353
// lb(x) : first greater or equal than x, ub(x) : first greater than x
template <class T> bool setmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template <class T> bool setmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
class dsu {
public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1), component_sets(n) {
        for (int i = 0; i < n; i++) {
            component_sets[i].insert(i);  // Initially, each vertex is its own component
        }
    }

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);

        // Merge component_sets[y] into component_sets[x]
        component_sets[x].insert(all(component_sets[y]));
        component_sets[y].clear();

        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    int kth_largest(int v, int k) {
        int root = leader(v);
        if (component_sets[root].size() < k) return -1;
        auto it = component_sets[root].rbegin();
        advance(it, k-1);
        return *it;
    }

private:
    int _n;
    vector<int> parent_or_size;
    vector<set<int>> component_sets;  // Store vertices in each component
};

void dxt(){
	int n,Q;
	cin >> n >> Q;

	dsu dsu(n);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v; u--; v--;  
            dsu.merge(u, v);
        } else if (t == 2) {
            int v, k;
            cin >> v >> k; v--; 
            if(dsu.kth_largest(v,k) == -1){
            	cout << -1 << endl;
            }
            else{
            	cout << dsu.kth_largest(v, k) + 1 << '\n';
            }
            
        }
    }
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	startTime = clock();
	int T = 1;
	// cin >> T;
	for (int i = 1; i <= T; i++) {
		// debug("--- Case #%d start ---", i);
		//printf("Case #%d: ", i);
		dxt();
		//cout << dxt() << endl;
		// debug("--- Case #%d end ---", i);
		// debug("time = %.5lf ", getCurrentTime());
		// debug("++++++++++++++++++++");

	}

	return 0;
} /* "So do not lose heart nor fall into despair, for you will be superior if you are true in faith!" */