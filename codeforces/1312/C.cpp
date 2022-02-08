#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
// use for unordered map (for high collison):
// um.reserve(4096); um.max_load_factor(0.25);
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;

#define PI 3.14159265

const int maX = 2 * 1e5 + 1;

#define rep(i,a,n) for (int i = a; i < n; i++)

#define PI 3.14159265

int _,n,k;
ll a[1010];
bool check() {
	set<int> s;
	for (int i = 0; i < n; i++) {
		ll t = a[i];
		int p = 0;
		while (t) {
			if(t % k > 1) {
				return 0;
			}
			if (t % k == 1) {
				if (s.count(p)) {
					return 0;
				}	
				s.insert(p);
			}
			p++;
			t = t / k;
		}
	}
	return 1;
}
int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		bool ok = check();
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}