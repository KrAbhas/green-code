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
 
bool bet (ll &a, ll &b, ll &c) {
	return (c >= a && c <= b);
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll tt;
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll w = 0; ll b = 0;
	for (int i = 0; i < n; i++){
		if(s[i] == 'W')
			w++;
		else b++;
	}
	if(w % 2 == 1 && b % 2 == 1) {
		cout << "-1\n";
		return 0;
	}
	vector<int> v;
	if (w % 2 == 1) {
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == 'B' && s[i + 1] == 'B') 
				v.push_back((i++ + 1));
			else if (s[i] == 'B') {
				v.push_back(i + 1);
				s[i + 1] = 'B';
			}
		}
	}
	else{
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == 'W' && s[i + 1] == 'W') 
				v.push_back((i++ + 1));
			else if (s[i] == 'W') {
				v.push_back(i + 1);
				s[i + 1] = 'W';
			}
		}
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
} 