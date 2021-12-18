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

bool isvalid(int k) {
	int valid[] = {1, 1, 1 , 0, 0, 1, 0, 0, 1, 0};
	while (k != 0) {
		if (!valid[k % 10])
			return false;
		k = k / 10;
	}
	return true;
}

int transform(int k) {
	string s = to_string(k);
	if (s.length() == 1) 
		s = '0' + s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '2')
			s[i] = '5';
		else if (s[i] == '5')
			s[i] = '2';
	}
	for (int i = 0; i < s.length() / 2; i++) {
		swap(s[i], s[s.length() - i - 1]);
	}
	return stoi(s);
}
int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		int h, m;
		cin >> h >> m;
		int hh, mm;
		string h_h, m_m;
		h_h = "";
		m_m = "";
		string s;
		cin >> s;
		h_h += s[0];
		h_h += s[1];
		m_m += s[3];
		m_m += s[4];
		hh = stoi(h_h);
		mm = stoi(m_m);
		int i = hh;
		int j = mm;
		int p = 0;
		for (i; i < h; i = (i + 1) % h) {
			bool check = isvalid(i) && (transform(i) < m);
			for (j; j < m; j++) {
				if (check && isvalid(j) && (transform(j) < h)){
					p = 1;
					hh = i;
					mm = j;
					break;
				}
				if (j == m - 1) {
					j = 0;
					break;
				}
			}
			if (p == 1)
				break;
		}
		h_h = to_string(hh);
		h_h = "0" + h_h;
		m_m = to_string(mm);
		m_m = "0" + m_m;
		int a = h_h.length();
		int b = m_m.length();
		cout << h_h[a - 2] << h_h[a - 1] << ":" << m_m[b - 2] << m_m[b - 1] << endl;
	}
} 