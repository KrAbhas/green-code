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
		ll n, m;
		cin >> n >> m;
		ll a, b, c;
		bool arr[n + 1];
		memset(arr, false, sizeof(arr));
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			arr[b] = true;
		}
		for (int i = 1; i <= n; i++) {
			if (!arr[i]) {
				c = i;
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if(i != c)
				cout << c << " " << i << "\n";
		}

	}
}