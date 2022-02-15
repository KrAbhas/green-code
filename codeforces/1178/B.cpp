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

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	vector<int> pref;
	vector<int> suff;
	pref.pb(0);
	suff.pb(0);
	int n = s.length();
	for (int i = 1; i < n; i++) {
		if (s[i] == 'v' && s[i - 1] == 'v') {
			pref.pb(pref.back() + 1);
		}
		else {
			pref.pb(pref.back());
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] == 'v' && s[i + 1] == 'v') {
			suff.pb(suff.back() + 1);
		}
		else {
			suff.pb(suff.back());
		}
	}
	reverse(suff.begin(), suff.end());
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			ans += (pref[i] * 1LL * suff[i]);
		}
	}
	cout << ans << endl;
}