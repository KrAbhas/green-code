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
 
const int maX = 1e9 + 7;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, tt;
	cin >> n >> m >> tt;
	while (tt--) {
		ll c, d, x, y;
		cin >> c >> d >> x >> y;
		ll t = __gcd (n, m);
		ll a = n / t;
		ll b = m / t;
		ll p, q;
		if (c == 2) {
			ll rem = d % b;
			if (rem == 0) rem = b;
			d = d - rem;
			p = d / b * a; 
		}
		else p = d - (d % a == 0? a: (d % a));
		if (x == 2) {
			ll rem = y % b;
			if (rem == 0) rem = b;
			y = y - rem;
			q = y / b * a; 
		}
		else q = y - (y % a == 0? a: (y % a));
		if (p == q) cout << "YES\n";
		else cout << "NO\n";
	}
}