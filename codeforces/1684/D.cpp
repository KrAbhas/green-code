#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
// use for unordered map (for high collison) with 2^x:
// um.reserve(4096); um.max_load_factor(0.25);
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
typedef pair<ll, ll> pi;
 
#define PI 3.14159265
const ll inf = 1e9 + 7;
const ll maxx = 2 * 1e5 + 10;
const ll mn = 1025;

const int maX = 1e5 + 1;
bool comp[maX];
inline void sieve() {
	memset(comp, false, sizeof(comp));
	comp[0] = true; comp[1] = true;
	for (int i = 2; i * i < maX; i++) {
		if (!comp[i])
			for (int j = 2 * i; j < maX; j += i) {
				comp[j] = true;
			}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		ll s = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
			a[i] -= n - i - 1;
		}
		sort (all (a), greater<int>());
		ll t = 0;
		for (int i = 0; i < k; i++) {
			t += a[i];
		}
		//cout << s - t << endl;
		cout << s - t - k * 1LL * (k - 1) / 2 << endl;
	}
}