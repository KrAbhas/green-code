#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
// use for unordered map (for high collison) with 2^x:
// um.reserve(4096); um.max_load_factor(0.25);
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;
 
#define PI 3.14159265
const ll inf = 1e9 + 7;
const int maX = 2 * 1e5 + 10;
const int mn = 1010;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string sa, sb;
	cin >> sa >> sb;
	vector<int> ba, ab;
	for (int i = 0; i < n; i++) {
		if (sa[i] == 'b' && sb[i] == 'a') {
			ba.pb(i + 1);
		}
		else if (sa[i] == 'a' && sb[i] == 'b') {
			ab.pb(i + 1);
		}
	}
	int k = 0;
	vector<pi> ans;
	if ((ba.size() + ab.size()) % 2 != 0) {
		cout << -1 << endl;
	}
	else {
		int a = 0;
		int b = 0;
		for (a; a < (int)ab.size() - 1; a += 2) {
			ans.push_back({ab[a], ab[a + 1]});
		}
		for (b; b < (int)ba.size() - 1; b += 2) {
			ans.push_back({ba[b], ba[b + 1]});
		}
		if (a < ab.size() && ab.size() > 0) {
			ans.push_back({ab[a], ab[a]});
			ans.push_back({ab[a], ba[b]});
		}
		cout << ans.size() << endl;
		if (ans.size() == 0)
			return 0;
		for (pi p: ans) {
			cout << p.first << ' ' << p.second << endl;
		}
	}
}