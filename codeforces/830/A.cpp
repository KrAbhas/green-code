#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e17;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k, p;
	cin >> n >> k >> p; 
	vector<ll> a(n);
	vector<ll> b(k);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < k; i++) cin >> b[i];
	sort (all(a));
	sort (all(b));
	ll dp[k + 1][n + 1];
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	//push dp
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= n; j++) {
			if (j < n)
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], abs(a[j] - b[i]) + abs(b[i] - p)));
			dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
		}
	}
	cout << dp[k][n] << endl;
}