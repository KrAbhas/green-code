#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fact(a,b) factorial (a, b)
#define fo(i, a, n) for (int i = a; i < n; i++)

class dsu {
public:
	vector<int> p;
	int n;
	dsu (int k) : n(k) {
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

//***************************************************************************

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll tt;
	cin >> tt;
	while(tt--) {
		ll n;
		cin >> n;
		ll l, r;
		cin >> l >> r;
		vector<int> vec(n);
		fo(i, 0, n) cin >> vec[i];
		sort (vec.begin(), vec.end());
		ll sum = 0;
		fo (i, 0, n) {
			int d = r - vec[i];
			auto up = upper_bound(vec.begin() + i + 1, vec.end(), d);
			d = l - vec[i];
			auto low = lower_bound(vec.begin() + i + 1, vec.end(), d);
			//cout << (up - low) << endl;
			sum += (up - low);
		}
		cout << sum << endl;
	}
} 