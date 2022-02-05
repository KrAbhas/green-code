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
		string s;
		cin >> s;
		n = s.length();
		vector<int> a;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'o') {
				if (i - 2 >= 0 && s[i - 2] == 't' && s[i - 1] == 'w') {
					if (i + 1 < n && s[i + 1] == 'o') {
						a.pb(i);
					}
					else {
						a.pb(i + 1);
					}
				}
				else if (i + 2 < n && s[i + 1] == 'n' && s[i + 2] == 'e') {
					if (i > 0 && s[i - 1] == 'o') {
						a.pb(i + 2);
					}
					else a.pb(i + 1);
				}
			}
		}
		cout << a.size() << endl;
		for (int i: a) cout << i << ' ';
		cout << endl;
	}
}