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

const int maX = 1e3 + 1;
bool comp[maX];
inline void sieve() {
	memset(comp, false, sizeof(comp));
	comp[0] = true; comp[1] = true;
	for (int i = 2; i * i < maX; i++) {
		if (!comp[i])
			for (int j = 2 * i; j < maX; j += i) {
				comp[j] = true;
			}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1;
	cin >> tt;
	sieve();
	int arr[] = {0,1,0,0,1,0,1,0,1,1};
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		bool ok = false;
		vector<char> vec(n);
		for (int i = 0; i < n; i++) cin >> vec[i];
		for (int i = 0; i < n; i++) a[i] = vec[i] - '0';
		for (int i = 0; i < n; i++) {
			if (arr[a[i]]) {
				cout << 1 << endl << a[i] << endl;
				ok = true;
				break;
			}
		}
		if (ok)
			continue;
		int k;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				k = a[i] * 10 + a[j];
				if (comp[k]) {
					cout <<2 << endl << k << endl, ok = true;
					break; 
				}
			}
			if (ok)
				break;
		}
	}
}