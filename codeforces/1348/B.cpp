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
int maX = 1e6 + 1;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		bool ok = true;
		unset<int> s;
		for (int i = 1; i < n; i++) {
			if (a[i] != a[i - 1])
				ok = false;
		}
		if (k == 1) {
			if (ok) {
				cout << n << endl;
				for (int i = 0; i < n; i++) {
					cout << a[i] << ' ' ;
				}
				cout << endl;
			}
			else cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < n; i++) {
			s.insert(a[i]);
		}
		if (s.size() > k) {
			cout << "-1\n";
			continue;
		}
		for (int i = 1; i <= k; i++) {
			if (s.size() == k) {
				break;
			}
			if (s.count(i) == 0) {
				s.insert(i);
			}
		}
		cout << n * k << endl;
		for (int i = 0; i < n; i++) {
			for (int j: s) {
				cout << j << ' ';
			}
		}
		cout << endl;

	}
}