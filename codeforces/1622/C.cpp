#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fact(a,b) factorial (a, b)
#define fo(i, a, n) for (ll i = a; i < n; i++)
#define fob(i, a, n) for (ll i = a; i >= n; i--)
#define all(x) x.begin(),x.end()
 
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

struct tri{
	ll a, b, c;
};
typedef struct tri triple; 

bool my_cmp(const triple &a, const triple &b) {
	if (a.a == b.a)
		return a.b > b.b;
	return a.a < b.a;
}
 
//***************************************************************************implement

ll factor(ll k) {
	ll f = 1;
	for (ll i = 2; i <= k; i++) {
		f *= i;
	}
	return f;
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll tt;
	cin >> tt;
	while (tt--) {
		ll n;
		cin >> n;
		ll k;
		cin >> k;
		vector<ll> vec(n);
		for (ll i = 0; i < n; i++) {
			cin >> vec[i];
		}
		sort (vec.begin(), vec.end());
		for (int i = 0; i < n; i++) {
			if (i != 0)
				vec[i] = vec[i] + vec[i - 1];
		}
		ll t = vec[n - 1] - k;
		if (t <= 0) {
			cout << 0 << endl;
			continue;
		}
		for (ll i = n - 1; i > 0; i--) {
			ll a = vec[i - 1] + vec[0] * (n - i);
			ll m = ceil(max(0ll, a - k) / (double)(n - i + 1));
			t = min(t, m + (n - i));
		}
		cout << t << endl;
	}
} 