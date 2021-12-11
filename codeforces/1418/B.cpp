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
		int arr[n];
		bool lock[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		vector<int> v;
		for (int i = 0; i < n; i++) {
			cin >> lock[i];
			if (lock[i] == 0) {
				v.push_back(arr[i]);
			}
		}
		sort(v.begin(), v.end());
		int j = 0; int t = 0;
		for (int i = 0; i < n; i++) {
			if (lock[i] == 1) {
				cout << arr[i] << " ";
				if (i != 0)
					arr[i] = arr[i - 1] + arr[i];
				continue;
			}
			if (i == 0) {
				cout << v[v.size() - 1] << " ";
				arr[i] = arr[i - 1] + v[v.size() - 1];
				v.pop_back();
				continue;
			}
			cout << v[v.size() - 1] << " ";
			arr[i] = arr[i - 1] + v[v.size() - 1];
			v.pop_back();
		}
		cout << endl;
	} 
} 