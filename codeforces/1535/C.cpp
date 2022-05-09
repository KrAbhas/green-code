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
const int maX = 2 * 1e5 + 10;
const int mn = 1025;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int n = s.length();
		ll ans = 0;
		ll k = 0;
		int last = -1;
		for (int i = 0; i < n; i++) {
			ans += k;
			if (s[i] != '?') {
				if (last != -1) {
					if ((i - last) & 1) {
						if (s[i] == s[last])
							k = i - last - 1;
					}
					else {
						if (s[i] != s[last])
							k = i - last - 1;
					}
				}
				last = i;
			}
			k++;
		}
		ans += k;
		cout << ans << endl;
	}
}