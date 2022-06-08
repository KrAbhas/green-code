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
typedef pair<int,int> pi;
 
#define PI 3.14159265
const ll inf = 1e9 + 7;
const ll maxx = 2 * 1e5 + 10;
const ll mn = 1025;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		int n;
		string s;
		cin >> n >> s;
		char arr[2] = {'*', '*'};

		for (int i = 0; i < n / 2; i++) {
			if (s[i] != s[n - i - 1]) {
				arr[0] = s[i];
				arr[1] = s[n - i - 1];
				break;
			}
		}
		if (arr[0] == '*') {
			cout << 0 << endl;
			continue;
		}
		int ans = INT_MAX;
		int k = 0;
		int l = 0;
		int r = n - 1;
		while (l < r) {
			if (s[l] != s[r]) {
				if (s[l] == arr[0])
					l++, k++;
				else if (s[r] == arr[0])
					r--, k++;
				else {
					k = -1;
					break;
				}
			}
			else l++, r--;
		}
		if (k != -1)
			ans = k;
		l = 0, r = n - 1, k = 0;
		while (l < r) {
			if (s[l] != s[r]) {
				if (s[l] == arr[1])
					l++, k++;
				else if (s[r] == arr[1])
					r--, k++;
				else {
					k = -1;
					break;
				}
			}
			else l++, r--;
		}
		if (k != -1)
			ans = min(ans, k);
		if (ans == INT_MAX)
			cout << -1 << endl;
		else cout << ans << endl;
	}
}