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

bool touch(int k, int end) {
	if (k - 1 == 0 || k - 1 <= end) {
		return true;
	}
	return false;
}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> row(n);
	vector<int> col(m);
	for (int i = 0; i < n; i++) {
		cin >> row[i];
	}
	for (int j = 0; j < m; j++) {
		cin >> col[j];
	}
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((touch(j, row[i - 1]) && j > row[i - 1] && i <= col[j - 1]) || (touch(i, col[j - 1]) && i > col[j - 1] && j <= row[i - 1])) {
				cout << 0 << endl;
				return 0;
			}
			if (!touch(j, row[i - 1]) && !touch(i, col[j - 1])) {
				ans = (ans * 2) % maX;
			}
		}
	}
	cout << ans << endl;
}