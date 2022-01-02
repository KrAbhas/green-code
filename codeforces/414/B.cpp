#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	ll dp[k + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][1] = 1;
	for (int i = 0; i < k; i++) {
		for (int j = 1; j <= n; j++) {
			for (int v = j; v <= n; v += j) {
				dp[i + 1][v] = (dp[i + 1][v] + dp[i][j]) % inf;
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + dp[k][i]) % inf;
	}
	cout << ans << endl;
}