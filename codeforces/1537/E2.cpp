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
	ll tt;
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int r = n;
	int j = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] > s[j]) {
			r = i - j;
			j = 0;
			break;
		}
		else if (s[i] == s[j]) {
			j++;
		}
		else {
			j = 0;
		}
	}
	r -= j;
	for (int i = 0; i < k; i++) {
		cout << s[i % r];
	}
	cout << endl;
}