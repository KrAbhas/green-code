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
int dp[55][10];

int n, m;
vector<string> s;
int main(){
	const ll inf = 1e5 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = inf;
		}
	}
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		s.pb(str);
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (s[i][k] <= '9' && s[i][k] >= '0')
				s[i][k] = '0';
			else if (s[i][k] <= 'z' && s[i][k] >= 'a')
				s[i][k] = '1';
			else {
				s[i][k] = '2';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][s[i][j] - '0'] = min({dp[i][s[i][j] - '0'], m - j, j});
		}
	}
	int ans = inf;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i != j && j != k && k != i) {
					ans = min(ans, dp[i][0] + dp[j][1] + dp[k][2]);
				}
			}
		}
	}
	cout << ans << endl;
}