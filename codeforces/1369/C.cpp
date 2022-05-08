#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
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
const int maX = 2 * 1e5 + 10;
const int mn = 1025;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		vector<int> b(m);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort (all(a), greater<int>());
		sort (all(b));
		ll ans = 0;
		int p = 0;
		for (int i = 0; i < m; i++) {
			if (b[i] == 1)
				ans += 2 * a[p];
			else ans += a[p];
			p++;
		}
		p = 0;
		sort (all(a));
		sort (all(b), greater<int>());
		for (int i = 0; i < m; i++) {
			if (b[i] == 1)
				break;
			ans += a[p];
			p += b[i] - 1;
		}
		cout << ans << endl;
	}
}