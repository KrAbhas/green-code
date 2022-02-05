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
		int n;
		cin >> n;
		string x;
		unmap<string, int> m;
		vector<string> a;
		for (int i = 0; i < n; i++) {
			cin >> x;
			a.pb(x);
			m[x]++;
		}
		int res = 0;
		for (auto [p, q]: m) {
			res += q - 1;
		}
		cout << res << endl;
		unmap<string,int> t;
		for (int i = 0; i < n; i++) {
			if (t.find(a[i]) == t.end()) t[a[i]] = 0;
			if (m[a[i]] == 1) {
				cout << a[i] << endl;
			}
			else {
				m[a[i]]--;
				string str = a[i];
				while (m[a[i]]) {
					a[i][0] = char(t[str] + '0');
					t[str] = (t[str] + 1) % 10;
				}
				m[a[i]]++;
				cout << a[i] << endl;
			}
		}
	}
}