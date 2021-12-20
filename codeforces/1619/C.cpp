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
	while(tt--) {
		string a, c;
		cin >> a >> c;
		int m = a.length();
		int n = c.length();
		int k = n - 1;
		bool ok = true;
		string str = "";
		for (int i = m - 1; i >= 0; i--) {
			string s1 = "";
			if (k < 0) {
				ok = false;
				break;
			}
			if (a[i] == c[k]) {
				str = '0' + str;
				k--;
			}
			else if (a[i] < c[k]) {
				str = to_string((c[k] - a[i])) + str;
				k--;
			}
			else {
				if (k <= 0) {
					ok = false;
					break;
				}
				s1 = to_string((stoll(c.substr(k - 1, 2)) - (int)(a[i] - '0')));
				if (stoll(s1) > 9 || (stoll(c.substr(k - 1, 2)) - (int)(a[i] - '0')) <= 0) {
					ok = false;
					break;
				}
				str = s1 + str;
				k -= 2;	
			}
		}
		string s = "";
		for (int i = k; i >= 0; i--) {
			s = c[i] + s;
		}
		str = s + str;
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		//cout << str << endl;
		cout << stoll(str) << endl;
	}
} 