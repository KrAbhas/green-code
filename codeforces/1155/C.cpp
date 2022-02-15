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
typedef pair<int, int> pi;
 
#define PI 3.14159265
 
const int maX = 1e5 + 10;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	ll k = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i != 0) {
			k = __gcd(k, a[i] - a[i - 1]);
		}
	}
	ll p = 0;
	bool ok = false;
	for (int i = 0; i < m; i++) {
		cin >> p;
		if (k % p == 0 && !ok) {
			cout << "YES\n" << a[0] << ' ' << i + 1 << endl;
			ok = true;
		}
	}
	if (!ok)
		cout << "NO\n";
}