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

bool my_cmp(const pair<ll,ll> &a, const pair<ll,ll> &b) {
	return a.second < b.second;
}

//***************************************************************************implement

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll tt;
	cin >> tt;
	while(tt--) {
		ll n, m;
		cin >> n >> m;
		ll arr[n][m];
		for (ll i = 0; i < n; i++) {
			for(ll j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		ll a = ceil(n / 2.0);
		ll b = ceil(m / 2.0);
		ll res = 0;
		ll mean;
		for (ll i = 0; i < a; i++) {
			for(ll j = 0; j < b; j++) {
				vector<ll> v;
				ll c = 1;
				v.push_back(arr[i][j]);
				int p = n - 1 - i;
				int q = m - 1 - j;
				if (i == p && j == q) continue;
				if (i == p) {
					res += abs(arr[i][q] - arr[i][j]);
				}
				else if (j == q) {
					res += abs(arr[p][j] - arr[i][j]);
				}
				else {
					v.push_back(arr[p][j]);
					v.push_back(arr[i][q]);
					v.push_back(arr[p][q]);
					sort (v.begin(), v.end());
					int med = (v[2] + v[1]) / 2;
					res += abs(arr[i][j] - v[2]) + abs(arr[i][q] - v[2]) + abs(arr[p][j] - v[2]) + abs(arr[p][q] - v[2]);
				}
			}
		}
		cout << res << endl;
	}
} 