#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
// use for unordered map (for high collison):
// um.reserve(4096); um.max_load_factor(0.25);
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<ll, ll> pi;
 
#define PI 3.14159265
 
const ll maX = 2 * 1e5 + 1;

bool good(ll m, ll k, ll a, ll b) {
	ll reqgood = ceil(k / 2.0);
	return reqgood > (m / (a + b)) * a + min(m % (a + b), a);
}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--) {
		ll n, g, b;
		cin >> n >> g >> b;
		ll l = 0, r = inf;
		while (l + 1 < r) {
			ll m = (l + r) / 2;
			if (good(m, n, g, b)) {
				l = m;
			}
			else r = m;
		}
		cout << max(r, n) << endl;
	}
}