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
 
bool bet (ll &a, ll &b, ll &c) {
	return (c >= a && c <= b);
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
		cin >> k;
		char ch;
		ll last = -k - 1;
		ll res = 0;
		for (int i = 0; i < n; i++) {
			cin >> ch;
			if (ch == '0' && last + k + 1 <= i) {
				res++;
				//cout << (last + k + 1) << endl;
				last = i;
			}
			if (ch == '1') {
				if (i != 0 && last + k + 1 > i)
					res--;
				last = i;
			}
		}
		cout << res << endl;
		//cout << endl;
	}
} 