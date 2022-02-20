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
ll arr[3];
int n;
int a[maX];

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> arr[0] >> arr[1] >> arr[2];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<ll>> dp(n + 1, vector<ll>(3, -inf));
	dp[0][0] = arr[0] * a[0];
	for (int i = 1; i < 3; i++) {
		dp[0][i] = arr[i] * a[0] + dp[0][i - 1]; 
	}
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], arr[0] * a[i]);
		dp[i][1] = max(dp[i - 1][1], arr[1] * a[i] + dp[i][0]);
		dp[i][2] = max(dp[i - 1][2], arr[2] * a[i] + dp[i][1]);
	}
	cout << dp[n - 1][2] << endl;
}