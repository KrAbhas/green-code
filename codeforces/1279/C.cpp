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
 
const int maX = 2 * 1e6 + 1;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, t; 
		cin >> n >> t;
		vector<int> a(n);
		vector<int> b(t);
		vector<bool> seen(n + 1, false);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < t; i++) cin >> b[i];
		ll res = 0;
		ll r = 0;
		ll k = 0;
		for (int i = 0; i < t; i++) {
			res++;
			if (seen[b[i]])
				continue;
			for (r; r < n; r++) {
				seen[a[r]] = true;
				if (a[r] == b[i]) break;
			}
			res += 2 * (r - i);
		}
		cout << res << endl;
	}
}