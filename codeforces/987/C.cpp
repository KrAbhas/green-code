#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e17;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	ll s[n];
	ll c[n];
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) cin >> c[i];
	ll dp[n][3];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = inf;
		}
	}
	for (int i = 0; i < n; i++) {
		dp[i][0] = c[i];
		for (int j = 1; j < 3; j++) {
			for (int k = 0; k < i; k++) {
				if (s[i] > s[k])
					dp[i][j] = min(dp[k][j - 1] + c[i], dp[i][j]);
			}
		}
	}
	ll m = inf;
	for (int i = 0; i < n; i++) {
		m = min(m, dp[i][2]);
	}
	if (m == inf)
		m = -1;
	cout << m << endl;
}