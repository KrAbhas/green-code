#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
// use for unordered map (for high collison) with 2^x:
// um.reserve(4096); um.max_load_factor(0.25);
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
typedef pair<int, int> pi;
 
#define PI 3.14159265
const ll inf = 1e18 + 7;
const int maxx = 2 * 1e5 + 10;
const int mn = 1010;

int c = 0;
int dfs (int u, vector<vector<int>> &g, vector<int> &a) {
	if((int)(g[u]).size()) {
		for (int i: g[u]) {
			a[u] += a[dfs(i, g, a)];
		}
	}
	if (a[u] == 0)
		c++;
	return u;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        c = 0;
        vector<int> v(n + 1);
        vector<int> a(n + 1);
        vector<vector<int>> g(n + 2);
        for (int i = 0; i < n - 1; i++) {
        	cin >> v[i];
        	v[i] = v[i] - 1;
        	g[v[i]].pb(i + 1);
        }
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
        	if (s[i] == 'W')
        		a[i]++;
        	else a[i]--;
        }
        dfs(0,g,a);
        cout << c <<endl;
    }
    return 0;
}