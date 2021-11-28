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
		int n;
		cin >> n;
		ll arr[n];
		int bit[33];
		memset(bit, 0, sizeof(bit));
		for (int i = 0; i < n; i++) {
			ll p = 1;
			int c = 0;
			cin >> arr[i];
			while(p <= arr[i]) {
				if(p & arr[i])
					bit[c]++;
				p = p << 1;
				c++;
			}
		}
		for (int k = 1; k <= n; k++) {
			int p = 0;
			for (int i = 0; i < 33; i++) {
				if (bit[i] % k != 0) {
					p = 1;
					break;
				}
			}
			if(p == 0) {
				cout << k << " ";
			}
		}
		cout << endl;
	}
}