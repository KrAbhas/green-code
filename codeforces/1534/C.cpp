#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fact(a,b) factorial (a, b)
#define fo(i, a, n) for (int i = a; i < n; i++)

class dsu {
public:
	vector<int> p;
	int n;
	dsu (int _n) : n(_n) {
		p.resize(n);
		iota(p.begin(), p.end(), 0);
	}

	inline int get(int x) {
		return (x == p[x] ? x : (p[x] = get(p[x])));
	}

	inline bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x != y) {
			p[x] = y;
			return true;
		}
		return false;
	}
};

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
		vector<vector<int>> a(2, vector<int>(n));
		fo(i,0,2) fo(j,0,n) {cin >> a[i][j]; --a[i][j];}
		vector<int> p(n);
		fo (i, 0, n) p[a[0][i]] = a[1][i];
		dsu d(n);
		fo (i, 0, n) d.unite(i, p[i]);
		ll ans = 1;
		fo (i, 0, n) {
			if (d.get(i) == i)
				ans = (ans * 2LL) % (ll)(1e9 + 7);
		}
		cout << ans << endl;
	}
} 