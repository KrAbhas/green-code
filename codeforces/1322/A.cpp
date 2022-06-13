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
	int n;
	string s;
	cin >> n >> s;
	int c = 0;
	int p = -1;
	int q = -1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			c++;
		else c--;
		if (c >= 0 && q - p)
			ans += q - p + 1;
		if (c >= 0) {
			p = i;
			q = i;
		}
		else {
			q++;
		}
	}
	if (c == 0) {
		cout << ans << endl;
	}
	else
		cout << -1 << endl;
}