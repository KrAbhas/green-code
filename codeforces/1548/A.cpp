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
	return a.second < b.second;
}
 
//***************************************************************************implement
int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	int cnt = n;
	vector<int> deg(n);
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u;
		cin >> v;
		u -= 1; v -= 1;
		if (u > v) swap(u, v);
		if (deg[u] == 0) cnt -= 1;
		deg[u] += 1;
	}
	int q;
	cin >> q;
	int k = 1;
	while (q--) {
		int qr;
		cin >> qr;
		if (qr == 1) {
			cin >> u >> v;
			u -= 1; v -= 1;
			if (u > v) swap(u, v);
			if (deg[u] == 0) cnt -= 1;
			deg[u] += 1;
		}
		else if (qr == 2) {
			cin >> u >> v;
			u -= 1; v -= 1;
			if (u > v) swap(u, v);
			deg[u] -= 1;
			if (deg[u] == 0) cnt += 1;
		}
		else if (qr == 3) {
			cout << cnt << endl;
		}
	}
} 