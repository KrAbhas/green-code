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
 
const ll maX = 1e9 + 7;

ll pos, neg, sign;

bool good (vector<ll> &a, ll med, ll n, ll k, ll lim) {
	ll s = 0;
	for (ll i = med; i < n; i++) {
		if (a[i] >= k) break;
		s += (k - a[i]);
		if (s > lim)
			return false;
	}
	return true;
}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	sort (all(a));
	ll med = n / 2;
	ll l = a[med];
	ll r = a[med] + k + 10;
	while (l + 1 < r) {
		ll m = (l + r) / 2;
		if (good(a, med, n, m, k)) l = m;
		else r = m;
	} 
	cout << l << endl;
}