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
		int c = 0;
		ll sum = 0;
		ll k = 2;
		ll a = 0;
		for (ll i = k - 1; sum < n; i = ((k = k << 1) - 1)) {
			sum = sum + i * (i + 1) / 2;
			if (sum <= n) {
				c++;
			}
		}
		cout << c << endl;
	}
} 