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
		int a, b;
		cin >> a >> b;
		int x = a % 4;
		if (x == 0)
			x = a;
		else if (x == 2) {
			x = a + 1;
		}
		else if (x == 3)
			x = 0;
		x = x ^ a;
		int l = a;
		if (x == b) {
			cout << l << endl;
		}
		else if ((x ^ a) == b)
			cout << l + 2 << endl;
		else cout << l + 1 << endl;
		
	}
}