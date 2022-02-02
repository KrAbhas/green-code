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

const int maX = 2 * 1e5 + 1;


int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> freq(n + 1);
		bool ok = true;
		for (int i = 0; i < n; i++) {
			freq[a[i]]++;
			if (freq[a[i]] == 3) {
				ok = false;
				break;
			}
		}
		int first = 0;
		int second = 0;
		for (int i = 1; i < n; i++) {
			if (freq[i] == 2) {
				first = i;
			}
			if (freq[i] != 0) {
				second = i;
			}
			if (i > 1 && freq[i] > freq[i - 1]) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout << 0 << endl;
			continue;
		}
		ok = true;
		vector<int> left(n + 1);
		vector<int> right(n + 1);
		set<int> l;
		int m = 0;
		for (int i = 0; i < n; i++) {
			asnmx(m, a[i]);
			left[a[i]]++;
			if (left[a[i]] == 2) {
				ok = false;
				break;
			}
			if (m == i + 1 && (m == first || m == second)) {
				l.insert(m);
				break;
			}
		}
		if (!ok) {
			cout << 0 << endl;
			continue;
		}
		m = 0;
		for (int i = n - 1; i >= 0; i--) {
			asnmx(m, a[i]);
			right[a[i]]++;
			if (right[a[i]] == 2) {
				ok = false;
				break;
			}
			if (m == n - i && (m == first || m == second)) {
				l.insert(n - m);
				break;
			}
		}
		if (!ok) {
			cout << 0 << endl;
			continue;
		}
		cout << l.size() << endl;
		for (int i: l) {
			cout << i << ' ' << n - i << endl;
		}
	}
}