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
		ll k = n + 2;
		ll sum = 0;
		ll brr[k];
		for (ll i = 0; i < k; i++) {
			cin >> brr[i];
			sum += brr[i];
		}
		sort(brr, brr + k);
		ll c = -1;
		ll p = 0;
		ll a = sum - brr[n + 1];
		ll b = a - brr[n];
		if (b == brr[n]) {
			for (ll i = 0; i < n; i++) {
				cout << brr[i] << " ";
			}
			cout << '\n';
			continue;
		}
		for (ll i = 0; i < n + 1; i++) {
			if (a - brr[i] == brr[n + 1]) {
				p = 1;
				c = i;
			}
		}
		if (p == 1) {
			for (ll i = 0; i < n + 1; i++) {
				if (c != i)
					cout << brr[i] << " ";
			}
		}
		if (p == 0)
			cout << "-1";
		cout << '\n';

	}
}