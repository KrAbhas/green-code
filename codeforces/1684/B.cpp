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

ll ans = 0;
char arr[10][10];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		ll a, b, c;
		cin >> a >> b >> c;
		ll z = c;
		ll y = z + b;
		ll x = y + a;
		cout << x << ' ' << y << ' ' << z << endl;
		// cout << x % y << endl << y % z << endl << z % x << endl;
	}
}