#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
// use for unordered map (for high collison) with 2^x:
// um.reserve(4096); um.max_load_factor(0.25);
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
typedef pair<ll, ll> pi;
 
#define PI 3.14159265
const ll inf = 1e9 + 7;
const ll maxx = 2 * 1e5 + 10;
const ll mn = 1025;

ll ans = 0;
int dp[maxx];

inline bool dfs(int v, vector<vector<int>>&a, vector<int>&vis) {
	vis[v] = 2;
	dp[v] = 0;
	bool ok = true;
	for (int u: a[v]) {
		if (vis[u] > 1) {
			return false;
		}
		else if (!vis[u]) {
			ok &= dfs (u, a, vis);
		}
		dp[v] = max(dp[v], dp[u] + (u > v));
	}
	vis[v] -= 1;
	return ok;
}

inline bool topological_sort(vector<vector<int>> &a, vector<int>&vis, int n) {
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			if (!dfs(i, a, vis))
				return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int k, x;
		ans = 0;
		vector<vector<int>> a(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> k;
			for (int j = 0; j < k; j++) {
				cin >> x;
				a[i + 1].pb(x);
			}
		}
		vector<int> vis(n + 1);
		if(!topological_sort(a, vis, n))
			cout << -1 << endl;
		else {
			for (int i = 1; i <= n; i++) {
				ans = max(ans, (ll)dp[i]);
			}
			cout << ans + 1 << endl;
		}
	}
}