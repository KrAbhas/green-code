#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e17;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	ll t, d;
	cin >> t >> d;
	ll dp[t][1000];
	for (ll i = 0; i < t; i++) {
		for (ll j = 0; j < 1000; j++){
			dp[i][j] = -inf;
		}
	}
	dp[0][n] = 0;
	for (ll i = 0; i < t - 1; i++) {
		for (ll j = 0; j < 1000; j++) {
			for (ll k = -d; k <= d; k++) {
				if (j + k >= 0 && j + k < 1000)
					dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + j);
			}
		}
	}
	cout << dp[t - 1][m] + m << endl;
}