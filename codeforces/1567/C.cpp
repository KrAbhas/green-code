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

ll fun (ll i, ll n, vector<ll> &a, vector<ll>&ways) {
	if (i == n - 1) return ways[a[n - 1]];
	else if (i == n - 2) return ways[a[n - 1]] * ways[a[n - 2]];
	int ans = ways[a[i]] * fun(i + 1, n, a, ways);
	if (a[i] == 0)
		return ans;
	a[i + 2] += 10;
	int res = ways[a[i] - 1] * fun (i + 1, n, a, ways);
	a[i + 2] -= 10;
	return ans + res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		ll n;
		cin >> n;
		vector<ll> a;
		while (n > 0) {
			a.pb(n % 10);
			n /= 10;
		}
		reverse(all(a));
		vector<ll> ways(20);
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j <= i; j++) {
				int k = i - j;
				if (k < 10 && j < 10) {
					ways[i]++;
				}
			}
		}
		n = sz(a);
		cout << fun(0, n, a, ways) - 2 << endl;
	}
}