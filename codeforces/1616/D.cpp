#include<bits/stdc++.h>
using namespace std;

#define ll long long

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
		int pref[n + 1];
		pref[0] = 0;
		for (ll i = 0; i < n; i++) {
			a[i] = a[i] - t;
			pref[i + 1] = pref[i] + a[i];
		}
		int mxpref = pref[0];
		int res = n;
		for (int i = 1; i < n; i++) {
			if ((pref[i + 1] - mxpref) < 0) {
				--res;
				mxpref = pref[i + 1];
				++i;
			}
			else {
				mxpref = max(mxpref, pref[i]);
			}
		}
		cout << res << endl;
	}
}