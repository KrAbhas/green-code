#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	ll s = 0;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
		if (i > 0)
			a[i] = a[i] + a[i - 1];
	}
	if (s % 3 != 0){
		cout << 0 << endl;
		return 0;
	}
	s = s / 3;
	vector<ll> dp[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0) {
				dp[i].pb(1);
			}
			else dp[i].pb(0);
		}
	}
	ll k = 0;
	for (int i = 0; i < n; i++) {
	for (int j = 1; j < 3; j++) {
			dp[j][i + 1] = dp[j][i];
			if (a[i] == s * j) {
				dp[j][i + 1] += dp[j - 1][i];
			}
		}
	}
	cout << dp[2][n - 1] << endl;
}