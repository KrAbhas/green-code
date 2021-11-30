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
		ll arr[n];
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		ll a = 1;
		ll d = arr[a] - arr[a - 1];
		for (ll i = 1; i < n; i++) {
			if (d >= arr[i] - arr[i - 1]) {
				d = arr[i] - arr[i - 1];
				a = i;
			}
		}
		cout << arr[a - 1] << " ";
		for (ll i = a + 1; i < n; i++) {
			cout << arr[i] << " ";
		}
		for (ll i = 0; i < a - 1; i++) {
			cout << arr[i] << " ";
		}
		cout << arr[a];
		cout << "\n";
	}
}