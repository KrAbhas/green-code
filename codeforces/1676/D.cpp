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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		ll ma = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int p = i;
				int q = j;
				ll c = 0;
				while (p - 1 >= 0 && q - 1 >= 0) {
					c += a[--p][--q];
				}
				p = i; q = j;
				while (p + 1 < n && q + 1 < m) {
					c += a[++p][++q];
				}
				p = i; q = j;
				while (p + 1 < n && q - 1 >= 0) {
					c += a[++p][--q];
				}
				p = i; q = j;
				while (p - 1 >= 0 && q + 1 < m) {
					c += a[--p][++q];
				}
				c += a[i][j];
				ma = max(ma, c);
			}
		}
		cout << ma << endl;
	}
}