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
 
const int maX = 2 * 1e5 + 7;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n; 
	vector<int> a(n);
	vector<int> v(maX);
	pi p = {0, -1};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v[a[i]]++;
		if (v[a[i]] > p.first) {
			p = {v[a[i]], i};
		}
	}
	int t = a[p.second];
	cout << n - p.first << endl;
	for (int i = p.second + 1; i < n; i++) {
		if (a[i] == t) continue;
		if (a[i] > t) {
			cout << 2 << ' ' << i + 1 << ' ' << i << endl;
		}
		else cout << 1 << ' ' << i + 1 << ' ' << i << endl;
	}
	for (int i = p.second - 1; i >= 0; i--) {
		if (a[i] == t) continue;
		if (a[i] > t) {
			cout << 2 << ' ' << i + 1 << ' ' << i + 2 << endl;
		}
		else cout << 1 << ' ' << i + 1 << ' ' << i + 2 << endl;
	}
}