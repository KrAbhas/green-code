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
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		vector<int> v;
		int n = s.length();
		int p = 0;
		for (int i = 1; i < n; i++) {
			int c = 0;
			if (s[i] == '1')
				p = 1;
			if (s[i - 1] != s[i] && s[i] == '0') {
				//cout << s[i];
				while (i < n && s[i] == '0') {
					i++;
					c++;
				}
				if (i < n)
					v.push_back(c);
			}
		}
		if (s[0] == '1')
				p = 1;
		ll res = (v.size() + 1) * a;
		if (p == 0){
			res = 0;
			cout << res << endl;
			continue;
		}
		//cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] * b < a) {
				res = res - a + v[i] * b;
			}
		}
		cout << res << endl;
	}
} 