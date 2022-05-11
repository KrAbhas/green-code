#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
// use for unordered map (for high collison) with 2^x:
// um.reserve(4096); um.max_load_factor(0.25);
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
typedef pair<int, int> pi;
 
#define PI 3.14159265
const ll inf = 1e9 + 7;
const int maX = 1e5 + 10;
const int mn = 1025;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		ll n;
		cin >> n;
		ll a = 0; ll b = 0;
		int k = 0;
		while (n > 0) {
			if (k % 2)
				a = a + (n % 10 * pow(10, k / 2));
			else b = b + (n % 10 * pow(10, k / 2));
			n /= 10;
			k++;
		}
		cout << (a + 1) * (b + 1) - 2 << endl;
	}
}