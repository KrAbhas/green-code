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
const int maxx = 2 * 1e5 + 10;
const int mn = 1010;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt; cin >> tt;
	while (tt--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		string p = "RGB";
		int m = maxx;
		for (int t: {0,1,2}) {
			vector<int> dp;
			int ch = 0;
			for (int j = 0; j < n; j++) {
				dp.pb(s[j] != p[(t + j) % 3]);
				ch += dp.back();
				if (j >= k) 
					ch -= dp[j - k];
				if (j >= k - 1)
					m = min(m, ch);
			}
		}
		cout << m << endl;
	}
}