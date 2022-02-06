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
 
const int maX = 1e6 + 1;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	set<int> s;
	vector<int> m(maX);
	vector<int> v;
	int c = 0;
	int k = 0;
	for (int i = 0; i < n; i++) {
		c++;
		if (a[i] == 0) {
			cout << -1 << endl;
			return 0;
		}
		m[abs(a[i])] += (a[i] / abs(a[i]));
		int t = m[abs(a[i])];
		if (t < 0 || t > 1) {
			cout << -1 << endl;
			return 0;
		}
		if (t == 1) {
			k++;
		} 
		else k--;
		if (s.count(a[i])){
			cout << -1 << endl;
			return 0;
		}
		else {
			s.insert(a[i]);
		}
		if (k == 0) {
			v.pb(c);
			s.clear();
			c = 0;
		}
	}	
	if (k != 0) {
		cout << -1 << endl;
		return 0;
	}
	if (c > 0) v.pb(c);
	cout << v.size() << endl;
	for (int i : v) cout << i << ' ';
	cout << endl;
}