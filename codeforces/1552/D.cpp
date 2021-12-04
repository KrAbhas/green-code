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
	int tt;
	cin >> tt;
	while(tt--) {
		ll n;
		cin >> n;
		bool p = false;
		ll arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			arr[i] = abs(arr[i]);
		}
		ll lim = pow(2, n);
		map<int, int> m;
		while (lim--) {
			ll sum = 0;
			ll i = 0;
			while ((1 << i) <= lim) {
				if ((1 << i) & lim) {
					sum += arr[i];
				}
				i++;
			}
			if (++m[sum] >= 2) {
				cout << "YES\n";
				p = true;
				break;
			}
		}
		if (!p) {
			cout << "NO\n";
		}
	}
}