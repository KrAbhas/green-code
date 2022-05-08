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
const ll inf = 1e9 + 7;
const int maX = 2 * 1e5 + 10;
const int mn = 1010;
int arr[] = {2,5};

void dfs (int u, int i, vector<vector<int>> &g, map<pi,int> &m, int r) {
	if ((int)g[u].size()) {
		int t = r;
		for (int v: g[u]) {
			if (v == i)
				continue;
			m[{v, u}] = arr[t];
			m[{u, v}] = arr[t];
			dfs(v, u, g, m, t ^ 1);
			t = t ^ 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	
	while (tt--) {
		int n;
		cin >> n;
		vector<vector<int>> g(n + 1);
		int x, y;
		vector<pi> a(n - 1);
		for (int i = 0; i < n - 1; i++) {
			cin >> a[i].first >> a[i].second;
			x = a[i].first;
			y = a[i].second;
			g[x].pb(y);
			g[y].pb(x);
		} 
		bool ok = true;
		map<pi,int> m;
		for (int i = 0; i < n + 1; i++) {
			if ((int)g[i].size() > 2)
				ok = false;
		}
		if (!ok)
			cout << -1;
		else {
			dfs (1, 0, g, m, 0);
			for (auto i : a) {
				cout << m[i] << ' ';
			}
		}
		cout << endl;
	}
}