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

bool my_cmp(const pair<int,int> &a, const pair<int,int> &b) {
	return a.second < b.second;
}

//***************************************************************************implement

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<pair<int,int>> v;
	int a;
	fo(i, 0, n) {cin >> a; v.push_back({a, i});}
	sort(v.begin(), v.end());
	ll s = 0;
	ll res = 1;
	fo(i, 0, k) {
		s += v[n - 1 - i].first; 
	}
	sort(v.end() - k, v.end(), my_cmp);
	cout << endl;
	fo (i, 0, k) {
		if (i == 0)
			continue;
		res = (res * abs(v[n - i - 1].second - v[n - i].second)) % 998244353;	
	}
	cout << s << " ";
	cout << res << endl;
} 