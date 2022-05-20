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

ll ans = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(m, vector<int>(n));
		vector<vector<int>> b(m, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[j][i];
				b[j][i] = a[j][i];
			}
		}
		sort (all (a));
		vector<int> v;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] != b[i][j]) {
					v.pb(i + 1);
					break;
				}
			}
		}
		bool ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (a[j][i] < a[j - 1][i]) {
					// cout << j << i << a[j][i] << a[j - 1][i];
					ok = false;
					break;
				}
			}
			if (!ok)
				break;
		}
		if (!ok)
			cout << -1 << endl;
		else if (sz(v) == 0) {
			cout << "1 1" << endl;
		}
		else if (sz(v) == 2) {
			for (int i: v)
				cout << i << ' ';
			cout << endl;
		}
		else cout << -1 << endl;
	}
}