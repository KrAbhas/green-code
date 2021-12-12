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
		int n;
		cin >> n;
		pair<int, ll> arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first;
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i].second;
		}
		int k = 0;
		sort(arr, arr + n, greater<pair<int,ll>>());
		for (int i = 0; i < n; i++) {
			//cout << arr[i].first << " ";
			if (i != 0)
				arr[i].second = arr[i].second + arr[i - 1].second;
		}
		for (int i = 0; i < n; i++, k++) {
			if (arr[i].second >= arr[i].first) {
				break;
			}
		}
		if (k != 0 && k != n)
			cout << min(max((ll)arr[k].first, arr[k - 1].second), arr[n - 1].second) << endl;
		else if (k == n) cout << min((ll)arr[k - 1].first, arr[k - 1].second) << endl;
		else cout << min((ll)arr[k].first, arr[k].second) << endl;
	} 
} 