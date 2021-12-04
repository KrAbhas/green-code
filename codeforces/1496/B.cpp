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
		ll k;
		ll lim = 1e5 + 1;
		map<int, bool> arr;
		cin >> k;
		ll a;
		ll ma = -1;
		for (ll i = 0; i < n; i++) {
			cin >> a;
			ma = max(ma, a);
			arr[a] = true;
		}
		ll me = ma + 1;
		for (ll i = 0; i < ma; i++) {
			if (!arr[i]){
				me = i;
				break;
			}
		}
		if (me == ma + 1) {
			cout << (k + n)<< endl;
		}
		else if (k != 0 && !arr[(ll)(ceil((ma + me) / 2.0))]){
			cout << (n + 1) << endl;
		}
		else {
			cout << n << endl;
		}
	}
} 