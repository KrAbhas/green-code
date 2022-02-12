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
	int n;
	cin >> n;
	vector<vector<int>> pref(log2(n) + 1, vector<int>(n + 1));
	for (int i = 0; i < n; i++) {
		cin >> pref[0][i + 1];
	}
	ll p = 1;
	for (int i = 1; i <= log2(n) + 1; i++) {
		p = p * 2;
		for (int j = p; j <= n; j++) {
			pref[i][j] = (pref[i - 1][j - p / 2] + pref[i - 1][j]) % 10;
		}
	}
	vector<vector<int>> dp(log2(n) + 1, vector<int>(n + 1));
	p = 1;
	for (int i = 1; i <= log2(n); i++) {
		p = p * 2;
		for (int j = p; j <= n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - p / 2];
			if (pref[i - 1][j] + pref[i - 1][j - p / 2] >= 10) {
				dp[i][j]++;
			}
		}
	}
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b;
		cin >> a >> b;
		int k = log2(b - a + 1);
		cout << dp[k][b] << endl;
	}
}