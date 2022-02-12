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
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		map<int,int> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
		}
		map<int,int, greater<int>> ff;
		for (auto [p, q]: m) {
			ff[q]++;
		}
		int ans = 0;
		int r = INT_MAX;
		for (auto [p, q]: ff) {
			r = min(r, p);
			int layer = min(r, q);
			ans += (r * (r + 1) / 2) - ((r - layer) * (r - layer + 1) / 2);
			r = r - layer;
			if (r == 0) break;
		}
		cout << ans << endl;
	}
}