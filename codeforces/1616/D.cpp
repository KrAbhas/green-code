#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define intl int64_t

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--){
		ll n;
		cin >> n;
		ll t = 0;
		vector<ll> a(n);
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}
		cin >> t;
		intl pref[n + 1];
		pref[0] = 0;
		for (ll i = 0; i < n; i++) {
			a[i] = a[i] - t;
			pref[i + 1] = pref[i] + a[i];
		}
		intl until = -1e18;
		intl pre = pref[0];
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (pref[i + 1] >= until) {
				++res;
				until = max(pre, until);
				pre = pref[i + 1];
			}
			else {
				until = -1e18;
				pre = pref[i + 1];
			}
		}
		cout << res << endl;
	}
}