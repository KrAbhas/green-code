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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	vector<vector<int>> b(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > b[i][j])
				swap(a[i][j], b[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		int k = 0;
		int l = 0;
		for (int j = 0; j < m; j++) {
			if (k >= a[i][j] || l >= b[i][j]) {
				cout << "Impossible\n";
				return 0;
			}
			k = a[i][j];
			l = b[i][j];
		}	
	}
	for (int i = 0; i < m; i++) {
		int k = 0;
		int l = 0;
		for (int j = 0; j < n; j++) {
			if (k >= a[j][i] || l >= b[j][i]) {
				cout << "Impossible\n";
				return 0;
			}
			k = a[j][i];
			l = b[j][i];
		}	
	}
	cout << "Possible\n";
}