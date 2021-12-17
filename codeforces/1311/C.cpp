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

ll factor(int k) {
	ll f = 1;
	for (int i = 2; i <= k; i++) {
		f *= i;
	}
	return f;
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt --) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int> v(m);
		for (int i = 0; i < m; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int l = 0;
		int arr[26];
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < m; i++) {
			for (int j = l; j < v[i]; j++) {
				arr[s[j] - 'a'] += m - i + 1;
			}
			l = v[i];
		}
		for (int i = l; i < n; i++) {
			arr[s[i] - 'a'] += 1;
		}
		for (int i = 0; i < 26; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
} 