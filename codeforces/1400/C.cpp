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
const int mn = 1010;
ll n, k;
string s;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		cin >> s;
		cin >> k;
		n = s.length();
		bool ok = true;
		vector<int> a(n, 1);
		for (int i = 0; i < n; i++) {
			if (i + k < n && s[i + k] == '0' || i >= k && s[i - k] == '0')
				a[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			int x = 0;
			if (s[i] == '1') {
				if (i >= k && a[i - k] == 1) {
					x++;
				}
				if (i + k < n && a[i + k] == 1) {
					x++;
				}
				if (x == 0) ok = false;
			}
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == -1) a[i] = 0;
		}
		if (!ok) cout << -1;
		else {
			for (int i : a) {
				cout << i;
			}
		}
		cout << endl;
	}
}