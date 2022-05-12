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
const ll maxx = 1e5 + 10;
const ll mn = 1025;

ll ans = 0;

void dfs(ll p, ll u, vector<vector<ll>> &g, vector<pi> &val, vector<pi>& dp) {
	for (ll v: g[u]) {
		if (p == v) continue;
		dfs(u, v, g, val, dp);
		dp[u].first += max(abs(val[u].first - val[v].second) + dp[v].second, abs(val[v].first - val[u].first) + dp[v].first);
		dp[u].second += max(abs(val[u].second - val[v].first) + dp[v].first, abs(val[u].second - val[v].second) + dp[v].second);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;

	while (tt--) {
		ll n;
		cin >> n;
		ans = 0;
		vector<pi> v(n + 1);
		vector<pi> dp(n + 1);
		for (ll i = 1; i <= n; i++) {
			cin >> v[i].first >> v[i].second;
		}
		vector<vector<ll>> g(n + 1);
		ll x, y;
		for (ll i = 0; i < n - 1; i++) {
			cin >> x >> y;
			g[y].pb(x);
			g[x].pb(y);
		}
		dfs(0, 1, g, v, dp);
		cout << max(dp[1].first, dp[1].second) << endl;
	}
}