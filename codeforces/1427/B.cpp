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
	int tt;
	cin >> tt;
	while (tt--) {
		ll n;
		cin >> n;
		ll k;
		cin >> k;
		vector<char> vec(n);
		int cnt = -1;
		vector<int> gap;
		ll w = 0;
		int t = 0;
		for (int i = 0; i < n; i++) {
			cin >> vec[i];
			if (vec[i] == 'W') {
				if(cnt > 0)
					gap.push_back(cnt);
				cnt = 0;
				w++;
				t++;
			}
			if (i != 0 && vec[i] == 'W' && vec[i - 1] == 'W') {
				w++;
			}
			if (cnt != -1 && vec[i] == 'L') cnt++;
		}
		sort(gap.begin(), gap.end());
		int j = 0;
		while (j < gap.size() && gap[j] <= k) {
			w += gap[j] * 2;
			t += gap[j];
			w++;
			k -= gap[j];
			j++;
		}
		if (t > 0 && k > 0) {
			w += min(k, n - t) * 2;
		}
		if (t == 0) {
			w += max(2 * min(k, n) - 1, 0LL);
		}
		cout << w << endl;
	} 
} 