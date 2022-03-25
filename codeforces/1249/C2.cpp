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
const ll inf = 1e18 + 7;
const int maX = 2 * 1e5 + 10;
const int mn = 1010;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		long long n;
		cin >> n;
		vector<int> vals;
		int pos2 = -1;
		while (n > 0) {
			vals.push_back(n % 3);
			if (vals.back() == 2) pos2 = int(vals.size()) - 1;
			n /= 3;
		}
		vals.push_back(0);
		if (pos2 != -1) {
			int pos0 = find(vals.begin() + pos2, vals.end(), 0) - vals.begin();
			vals[pos0] = 1;
			for (int i = pos0 - 1; i >= 0; --i) {
				vals[i] = 0;
			}
		}
		long long ans = 0;
		long long pw = 1;
		for (int i = 0; i < int(vals.size()); ++i) {
			ans += pw * vals[i];
			pw *= 3;
		}
		if (vals.back() == 1) ans = pw / 3;
		cout << ans << endl;
	}
}