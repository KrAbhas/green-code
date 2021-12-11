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
		ll a, b, c;
		cin >> a >> b >> c;
		if (c == a || c == b) {
			cout << "YES\n";
			continue;
		}
		if (c > a && c > b) {
			cout << "NO\n";
			continue;
		}
		if (a > b) swap(a, b);
		bool ok = false;
		while (!ok && a != 0 && b != 0) {
			if (c < a) {
				b = b % a;
			}
			else break;
			if (a > b) swap(a, b);
			if (c == a || c == b) {
				ok = true;
				break;
			}
		}
		if (a != 0 && c % a == b % a)
			ok = true;
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	} 
} 