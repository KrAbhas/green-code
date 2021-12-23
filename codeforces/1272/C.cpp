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
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int arr[26];
	char a;
	for (ll i = 0; i < k; i++) {
		cin >> a;
		arr[a - 'a'] = 1;
	}
	ll dp[n + 1];
	ll sum = 0;
	memset(dp, 0, sizeof(dp));
	dp[0] = 0;
	for (ll i = 1; i <= n; i++) {
		if (arr[s[i - 1] - 'a'] == 1)
			dp[i] = dp[i - 1] + 1;
		else dp[i] = 0;
		sum += dp[i];
	}
	cout << sum << endl;
} 