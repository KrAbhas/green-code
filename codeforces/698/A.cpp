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
int n;
int a[101];
int dp[101][3];

void fun(int i) {
	if (a[i] < 3) dp[i][a[i]] = 0;
	if (a[i] == 3) dp[i][1] = 0, dp[i][2] = 0;
	dp[i][0] = 1;
}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = maX;
		}
	}
	fun(0);
	for (int i = 1; i < n; i++) {
		dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
		if (a[i] == 1 || a[i] == 3)
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		if (a[i] == 2 || a[i] == 3)
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
	}
	cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
}