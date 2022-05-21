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
typedef pair<ll, ll> pi;
 
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
		ll l, r;
		cin >> l >> r;
		ll b = max(r / 2 + 1, l);
		ll a = min(2 * b, r);
		cout << (a % b) << endl;
	}
}