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
		int a;
		cin >> a;
		int b;
		int p = 0;
		for (int i = 1; i < n; i++) {
			cin >> b;
			if (a >= b) {
				p = 1;
			}
			a = b;
		}
		if (n % 2 == 0 || p == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}