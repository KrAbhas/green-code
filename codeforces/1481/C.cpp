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
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;
 
#define PI 3.14159265
const ll inf = 1e18 + 7;
const int maX = 2 * 1e5 + 10;
const int mn = 1010;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		vector<int> b(n);
		vector<int> c(m);
		map<int,pair<int,vector<int>>> mm;
		int k = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			if (a[i] != b[i]) {
				mm[b[i]].first++;
				mm[b[i]].second.pb(i + 1);
				k++;
			}
		}
		int p = 0;
		vector<int> ans(m);
		for (int i = 0; i < m; i++) {
			cin >> c[i];
			if (mm[c[i]].first) {
				mm[c[i]].first--;
				ans[i]=mm[c[i]].second.back();
				mm[c[i]].second.pop_back();
				k--;
			}
			else {
				p++;
			}
		}
		int r = -1;
		int t = n - 1;
		for (int i = 0; i < n; i++) {
			if (b[i] == c[m - 1]) {
				r = i + 1;
				break;
			}
		}
		if (ans[m - 1])
			r = ans[m - 1];
		else ans[m - 1] = r;
		if (k == 0 && p == 0) {
			cout << "YES\n";
			for (int i = 0; i < m; i++) {
				cout << ans[i] << ' ';
			}
			cout << endl;
		}
		else if (k == 0 && r != -1) {
			cout << "YES\n";
			for (int i = 0; i < m; i++) {
				if (ans[i])
					cout << ans[i];
				else cout << r;
				cout << ' ';
			}
			cout << endl;
		}
		else {
			cout << "NO\n";
		}
	}
}