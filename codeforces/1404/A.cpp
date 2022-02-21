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
 
const int maX = 1e5 + 10;
const int mn = 1010;
ll n, k;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while(tt--) {
		cin >> n >> k;
		string s;
		cin >> s;
		int c = -1;
		bool ok = true;
		int o = 0;
		int z = 0;
		for (int i = 0; i < k; i++) {
			if (s[i] == '0') 
				z++;
			else if (s[i] == '1')
				o++;
		}
		if (2 * o > k || 2 * z > k) {
			ok = false;
		}
		for (int i = 0; i < n - k; i++) {
			if (s[i + k] == '0') 
				z++;
			else if (s[i + k] == '1')
				o++;
			if (s[i] == '0') 
				z--;
			else if (s[i] == '1')
				o--;
			if (2 * o > k || 2 * z > k) {
				ok = false;
			}
		}
		o = 0; z = 0;
		for (int i = 0; i < k && ok; i++) {
			c = -1;
			for (int j = i; j < n; j += k) {
				if (s[j] == '?') continue;
				if (c == -1) {
					c = s[j] - '0';
				}
				else if (s[j] - '0' != c) {
					ok = false;
					break;
				}
			}
			if (c == 1) 
				o++;
			else if (c == 0)
				z++;
		}
		if (2 * o > k || 2 * z > k) {
			ok = false;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}