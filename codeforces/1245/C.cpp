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
 
const int maX = 1e9 + 7;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n = s.length();
	vector<int> a(n + 1);
	a[0] = 1;
	a[1] = 2;
	for (int i = 2; i < n + 1; i++) {
		a[i] = (a[i - 2] + a[i - 1]) % maX;
	}
	ll ans = 1;
	ll c = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'm' || s[i] == 'w') {
			cout << 0 << endl;
			return 0;
		}
		if (i == 0) continue;
		if (s[i] == s[i - 1] && (s[i] == 'n' || s[i] == 'u')) {
			c++;
		}
		else {
			ans = (ans * a[c]) % maX;
			c = 0;
		}
	}
	ans = (ans * a[c]) % maX;
	cout << ans << endl;
}