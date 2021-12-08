#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fact(a,b) factorial (a, b)
#define fo(i, a, n) for (ll i = a; i < n; i++)
#define fob(i, a, n) for (ll i = a; i >= n; i--)

//_____________________________________________________________________________DSU
class dsu {
public:
	vector<ll> p;
	ll n;
	dsu (ll k) : n(k) {
		p.resize(n);
		iota(p.begin(), p.end(), 0);
	}

	inline ll get(ll x) {
		return (x == p[x] ? x : (p[x] = get(p[x])));
	}

	inline bool unite(ll x, ll y) {
		x = get(x);
		y = get(y);
		if (x != y) {
			p[x] = y;
			return true;
		}
		return false;
	}
};
//---------------------------------------------------------------------------factorial, ncr
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

//***************************************************************************implement

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll tt;
	cin >> tt;
	while (tt--) {
		ll n;
		cin >> n;
		vector<pair<ll,ll>> pf;
		//cout << n << endl;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i != 0)
				continue;
			ll k = n;
			ll c = 0;
			while (k % i == 0 && k > 0) {
				k = k / i;
				c++;
				//cout << k << " ";
			}
			//cout << c <<i<< endl;
			pf.push_back({c, i});
		}
		if (pf.empty()) {
			pf.push_back({1, n});
		}
		//cout << pf[0].second << endl;
		sort (pf.begin(), pf.end(), greater<pair<ll,ll>>());
		ll k = pf[0].first;
		cout << pf[0].first << endl;
		for (ll i = 0; i < k - 1; i++) {
			cout << pf[0].second << " ";
		}
		cout << ((ll)(n / pow(pf[0].second, pf[0].first) * pf[0].second)) << endl;
	}
} 