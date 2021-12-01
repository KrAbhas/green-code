#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fact(a,b) factorial (a, b)

ll factorial (ll k, ll s) {
	ll f = 1;
	for (ll i = s; i <= k; i++) {
		f *= i;
	}
	return f;
}

ll ncr(ll n, ll r) {
	ll rd = n - r;
	ll m = min(r, rd);
	ll nf = fact(n, (rd + 1));
	ll rf = fact((n - m), 1);
	ll ans = nf * 1.0 / rf;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll tt;
	cin >> tt;
	while(tt--) {
		ll n;
		cin >> n;
		ll ans = 0;
		ll arr[n];
		ll k;
		ll m;
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			arr[i] = arr[i] - (i + 1);
			if (i == 0) {
				k = arr[i];
				m = k;
			}
			else {
				k = min(k, arr[i]);
				m = max(arr[i], m);
			}
		}
		ll p = 0;
		if (k < 0) 
			p = m + abs(k);
		else p = m;
		ll dp[p + 1];
		memset(dp, 0, sizeof(dp));
		if (k < 0)
			for (ll i = 0; i < n; i++) {
				ans += dp[(abs(k) + arr[i])]++;
				//cout << k + arr[i];
			}
		else 
			for (ll i = 0; i < n; i++) {
				ans += dp[arr[i]]++;
			}
		

		cout << ans;
		cout << "\n";
	}
}