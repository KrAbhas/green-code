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
		int n;
		vector<int> a(maX);
		cin >> n;
		int ans = maX;
		int x = 0;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (a[x]) {
				ans = min(ans, i + 1 - a[x]);
			}
			a[x] = i + 1;
		}
		if (ans != maX)
			cout << (n - ans) << endl;
		else cout << -1 << endl;
	}
}