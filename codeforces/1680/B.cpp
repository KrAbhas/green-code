#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
// use for unordered map (for high collison) with 2^x:
// um.reserve(4096); um.max_load_factor(0.25);
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
typedef pair<ll, ll> pi;
 
#define PI 3.14159265
const ll inf = 1e9 + 7;
const ll maxx = 1e5 + 10;
const ll mn = 1025;

ll ans = 0;
char arr[10][10];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;

	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}

		int k = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 'R') {
					arr[i][j] = 'X', k++;
					break;
				}
			}
			if (k == 1)
				break;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[j][i] == 'R' || arr[j][i] == 'X') {
					arr[j][i] = 'X', k++;
					break;
				}
			}
			if (k == 2)
				break;
		}
		k = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 'X')
					k++;
			}
		}
		if (k == 1)
			cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}