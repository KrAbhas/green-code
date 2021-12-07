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
		ll w;
		cin >> n;
		cin >> w;
		ll a;
		vector<ll> bin(21, 0);
		fo (i, 0, n) {
			cin >> a;
			int k = 1;
			int j = 0;
			while (!(k & a)) {
				k = k << 1;
				j++;
			}
			bin[j]++;
		}
		ll c = 0;
		int r = 1;
		int res = 0;
		while (r == 1) {
			ll k = w;
			r = 0;
			res++;
			for (int i = 20; i >= 0; i--) {
				if (bin[i] > 0) {
					r = 1;
					ll p = pow(2, i);
					//cout << i << " " ;
					if (p <= k) {
						ll q = min((k / p), bin[i]);
						//cout << p <<i<<q<<k<< " ";
						k -= (p * q);
						bin[i] -= q;
						
					}
				}
			}
			//cout << endl;
		}
		res--;
		cout << res << endl;
	}
} 