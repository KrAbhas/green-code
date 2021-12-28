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
	while (tt--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		string s;
		cin >> s;
		vector<pair<int,int>> ones;
		vector<pair<int,int>> zero;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0')
				zero.push_back({arr[i], i});
			else ones.push_back({arr[i], i});
		}
		//cout << zero.size() << ones.size() << endl;
		sort (zero.begin(), zero.end(), greater<pair<int,int>>());
		sort (ones.begin(), ones.end(), greater<pair<int,int>>());
		int k = n;
		for (int i = 0; i < n; i++) {
			if (i < ones.size()) {
				arr[ones[i].second] = k;
				k--;
			}
			else {
				arr[zero[i - ones.size()].second] = k;
				k--;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
} 