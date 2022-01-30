#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;

const ll maX = 998244353;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		int arr[n + 2][m + 2];
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				arr[i][j] = 0;
			}
		}
		char ch;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> ch;
				if (ch == '*') {
					arr[i + 1][j + 1] = 1;
				}
			}
		}
		for (int i = n - 1; i > 0; i--) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j])
					arr[i][j] += min({arr[i + 1][j + 1], arr[i + 1][j - 1], arr[i + 1][j]});
			}
		}
		int s = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				s += arr[i + 1][j + 1];
			}
		}
		cout << s << endl;
	}
}       	
