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
typedef pair<int, int> pi;
 
#define PI 3.14159265
const ll inf = 1e9 + 7;
const int maX = 2 * 1e5 + 10;
const int mn = 1010;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> v(n);
		for (int i = n - 1; i >= 0; i--) {
			int k = 0;
			for (int j = 0; j < n; j++) {
				if (a[j] == i + 1) {
					p[i] = (j + 1) % (i + 1);
					k = j;
					break;
				}
			}
			int r = 0;
			for (int j = k + 1; j < i + 1; j++) {
				v[r] = a[j];
				r++;
			}
			for (int j = 0; j <= k; j++) {
				v[r] = a[j];
				r++;
			}
			a = v;
		}
		for (int i: p)
			cout << i << ' ';
		cout << endl;
	}
}