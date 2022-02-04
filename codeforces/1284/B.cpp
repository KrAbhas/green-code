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
 
const ll maX = 2 * 1e6 + 1;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n; 
	vector<ll> a;
	vector<ll> v;
	ll x;
	ll t;
	ll r = 0;
	for (ll i = 0; i < n; i++) {
		cin >> t;
		ll p = 0; ll q = maX;
		bool ok = false;
		ll k = maX;
		for (ll j = 0; j < t; j++) {
			cin >> x;
			asnmn(q, x);
			asnmx(p, x);
			if (k < x) {
				ok = true;
			}
			k = x;
		}
		if (!ok) {
			a.push_back(p); //max
			v.push_back(q); //min
		}
		else r++;
	}
	t = v.size();
	ll b = n - t;
	ll c = b * n;
	sort(all(a));
	for (ll i = 0; i < t; i++) {
		c += a.end() - upper_bound(a.begin(), a.end(), v[i]) + r;
	}
	cout << c << endl;
}