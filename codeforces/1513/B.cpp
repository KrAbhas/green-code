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
 
ll sgn(ll &a, ll &b) {
	if (b - a > 0) return 1;
	if (b - a < 0) return -1;
	return 0;
}
 
bool my_cmp(const pair<ll,ll> &a, const pair<ll,ll> &b) {
	return (a.second - a.first + 1) > (b.second - b.first + 1);
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
		ll arr[n];
		ll a = 0;
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			if (i != 0) 
				a = a & arr[i];
			else a = arr[i];
		}
		ll cnt = 0;
		ll t = 0;
		t = ~0;
		for (ll i = 0; i < n; i++) {
			if (arr[i] == a) {
				cnt++;
			}
			else t = t & arr[i];
		}
		bool ok = false;
		if (cnt < 2) {
			cout << 0 << endl;
			continue;
		}
		if ((t & a) == a) {
			ll k = cnt * (cnt - 1);
			for (ll i = 2; i <= n - 2; i++) {
				k = (k * i) % (ll)(1e9 + 7);
			}
			cout << k << endl;
		}
		else cout << 0 << endl;
	} 
} 