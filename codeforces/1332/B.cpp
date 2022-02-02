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
// um.reserve(4096);
// um.max_load_factor(0.25);
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;

#define PI 3.14159265

const int maX = 1e6 + 1;
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
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	sieve();
	while (tt--) {
		int n;
		cin >> n;
		vector<vector<int>> a(1001);
		vector<int> b(n);
		int x;
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			a[b[i]].pb(i);
		}
		vector<vector<int>> res;
		for (int i = 2; i < 1000; i++) {
			if (comp[i]) continue;
			vector<int> v;
			for (int j = 2 * i; j <= 1000; j += i) {
				if (!a[j].empty()) {
					for (int k: a[j]) {
						v.pb(k);
					}
					a[j] = {};
				}
			}
			if (!v.empty()) {
				res.pb(v);
			}
		}
		cout << res.size() << endl;
		int p = 1;
		for (vector<int> k: res) {
			for (int i: k) {
				b[i] = p;
			}
			p++;
		}
		for (int i = 0; i < n; i++) {
			cout << b[i] << ' ';
		}
		cout << endl;
	}
}