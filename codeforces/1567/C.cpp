#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
// use for unordered map (for high collison) with 2^x:
// um.reserve(4096); um.max_load_factor(0.25);
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
typedef pair<int, int> pi;
 
#define PI 3.14159265
const ll inf = 1e9 + 7;
const int maX = 1e5 + 10;
const int mn = 1025;

ll ways (ll k, ll n, vector<ll> &a, vector<ll> &w) {
	if (k == n - 1) return w[a[n - 1]];
	else if (k == n - 2) return w[a[n - 1]] * w[a[n - 2]];
	ll ans = w[a[k]] * ways(k + 1, n, a, w);
	if (a[k] == 0) return ans;
	a[k + 2] += 10;
	ll res = w[a[k] - 1] * ways(k + 1, n, a, w);
	a[k + 2] -= 10;
	return ans + res; 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		ll n;
		cin >> n;
		vector<ll> a;
		while (n > 0) {
			a.pb(n % 10);
			n /= 10;
		}
		reverse(a.begin(), a.end());
		vector<ll> w(20);
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j <= i; j++) {
				int k = i - j;
				if (k < 10 && j < 10)
					w[i]++;
			}
		}
		n = sz(a);
		cout << ways(0, n, a, w) - 2 << endl;
	}
}