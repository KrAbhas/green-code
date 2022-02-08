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
	vector<vector<int>> a(2, vector<int> (n));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++) 
			cin >> a[i][j];

	vector<vector<ll>> dp(2, vector<ll> (n));
	
	if (n == 1) {
		cout << max({a[1][0], a[0][0]}) << endl;
		return 0;
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 2; i++) {
			dp[i][j] = a[i][j];
			if (j == 0) continue;
			if (j == 1)
				dp[i][j] += dp[i ^ 1][j - 1];
			else 
				dp[i][j] += max(dp[i ^ 1][j - 1], dp[i ^ 1][j - 2]);	
		}
	}
	cout << max({dp[1][n - 1], dp[0][n - 1], dp[1][n - 2], dp[0][n - 2]}) << endl;
}