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

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll tt;
	cin >> tt;
	while(tt--) {
		ll n, q;
		cin >> n >> q;
		vector<pair<ll,ll>> arr(n);
		fo (i, 0, n) {
			cin >> arr[i].first;
			arr[i].second = (i + 1);
		}
		ll s = 0;
		sort(arr.begin(), arr.end());
		ll k = 0;
		bool ok = false;
		fo (i, 0, n) {
			if(s + arr[i].first <= q){
				k = i;	
				s += arr[i].first;
			}
		}
		k++;
		if (s * 2 >= q) {
			cout << k << endl;
			fo (i, 0, k) {
				cout << arr[i].second << " ";
			}
			cout << endl;
		}
		else {
			fo (i, 0, n) {
				if (arr[i].first * 2 >= q && arr[i].first <= q) {
					cout << "1\n" << arr[i].second << endl;
					ok = true;
					break;
				}
			}
			if (!ok)
				cout << "-1\n";
		}
	}
} 