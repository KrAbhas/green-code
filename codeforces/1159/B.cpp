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
typedef pair<ll, ll> pi;
 
#define PI 3.14159265
 
const int maX = 1e5 + 10;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<pi> p(n);
	for (int i = 0; i < n; i++) {
		p[i] = {a[i], i};
	}
	sort (all(p));
	ll ans = 9999999999999999;
	for (int i = 0; i < n; i++) {
		ll x = 0, y = 0;
		if (a[n - 1] >= p[i].first) {
			y = n - 1 - p[i].second;
		}
		if (a[0] >= p[i].first) {
			x = p[i].second;
		}
		if (x == 0 && y == 0) continue;
		ans = min(ans, p[i].first / max(x, y));
	}
	cout << ans << endl;
}