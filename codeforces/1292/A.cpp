#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
// use for unordered map (for high collison) with 2^x:
// um.reserve(4096); um.max_load_factor(0.25);
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;
 
#define PI 3.14159265
 
const int maX = 2 * 1e5 + 1;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<bool> a[2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			a[j].pb(0);
		}
	}
	int lock = 0;
	while (q--) {
		int r,c;
		cin >> r >> c;
		r--; c--;
		a[r][c] = a[r][c] ^ 1;
		if (c == 0) {
			if (a[r][c] && (a[r - 1][c] || a[r - 1][c + 1])) {
				lock += a[r - 1][c] + a[r - 1][c + 1];
			}
			else if (a[r - 1][c] || a[r - 1][c + 1]) {
				lock -= a[r - 1][c] + a[r - 1][c + 1];
			}
		} 
		else if (c == n - 1) {
			if (a[r][c] && (a[r + 1][c] || a[r + 1][c - 1])) {
				lock += a[r + 1][c] + a[r + 1][c - 1];
			}
			else if (a[r + 1][c] || a[r + 1][c - 1]) lock -= a[r + 1][c] + a[r + 1][c - 1];
		}
		else if (r == 1) {
			if (a[r][c] && (a[r - 1][c] || a[r - 1][c - 1] || a[r - 1][c + 1])) {
				lock += a[r - 1][c] + a[r - 1][c - 1] + a[r - 1][c + 1];
			}
			else if (a[r - 1][c] || a[r - 1][c - 1] || a[r - 1][c + 1]) {
				lock -= a[r - 1][c] + a[r - 1][c - 1] + a[r - 1][c + 1];
			}
		}
		else if (r == 0) {
			if (a[r][c] && (a[r + 1][c] || a[r + 1][c - 1] || a[r + 1][c + 1])) {
				lock += a[r + 1][c] + a[r + 1][c - 1] + a[r + 1][c + 1];
			}
			else if (a[r + 1][c] || a[r + 1][c - 1] || a[r + 1][c + 1]) lock -= a[r + 1][c] + a[r + 1][c - 1] + a[r + 1][c + 1];
		}
		if (lock == 0) {
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
}