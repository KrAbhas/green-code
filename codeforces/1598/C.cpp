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
		ll c = 0;
		cin >> n;
		ll arr[n];
		map<ll, ll> mp;
		ll p = 0;
		ll a;
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			p += arr[i];
			arr[i] *= n;
		}
		//sort (arr, arr + n);
		for (int i = 0; i < n; i++) {
			ll v1 = p * 2LL;
			ll v2 = arr[i];
			if(mp.find((v1 - v2)) != mp.end()) {
				c += mp[(v1 - v2)];
			}
			mp[arr[i]]++;
		}
		cout << c <<"\n";
	}
}