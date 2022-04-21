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
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;
 
#define PI 3.14159265
const ll inf = 1e9 + 7;
const int maxx = 2 * 1e5 + 10;
const int mn = 1010;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1; cin >> tt;
	while (tt--) {
		int n, a, b; string s;
		cin >> n >> a >> b >> s;
		bool state = 0; bool tstate = 0;
		ll p = 0; ll q = 0;
		ll c = 0;
		for (int i = 0; i < n; i++) {
			c += a + b;
			if (!state && i < n - 1 && s[i] == '0' && s[i + 1] == '1') {
				c += a;
				state = !state;
				tstate = state;
			}
			else if (state) {
				q += b;
				if (tstate) {
					p += b;
				}
				if (tstate && i < n - 1 && s[i + 1] == '0' && s[i] == '0') {
					p += a;
					tstate = !tstate;
				}
				
				if (i < n - 1 && s[i + 1] == '1' && s[i] == '0') {
					if (!tstate) {
						p += a;
					}
					tstate = state;
					if (q <= p) {
						c += q;
						p = q = 0;
					}
					else {
						c += p;
						p = q = 0;
					}
				}
			}
		}
		if (state) {
			q += a;
			if (tstate)
				p += a;
			c += min(p, q);
		}
		c += b;
		cout << c << endl;
	}
}