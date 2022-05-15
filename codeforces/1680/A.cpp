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
const ll maxx = 1e5 + 10;
const ll mn = 1025;

ll ans = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;

	cin >> tt;
	while (tt--) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int k = -1;
		if ((a >= c && a <= d))
			k = a;
		else if (c >= a && c <= b)
			k = c;
		else k = a + c;
		cout << k << endl;
	}
}