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
 
const int maX = 2 * 1e6 + 1;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, p, k;
		cin >> n >> p >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int x = 0; int y = 0;
		int q = 0; int t = n;
		sort (all(a));
		for (int i = 1; i < n; i += 2) {
			if (q + a[i] > p)
				break;
			q += a[i];
			x += 2;
			t = i;
		}
		if (t + 1 < n && q + a[t + 1] <= p) {
			x++;
		}
		q = a[0]; t = n;
		if (q <= p) y++;
		for (int i = 2; i < n; i += 2) {
			if (q + a[i] > p) {
				break;
			}
			q += a[i];
			y += 2;
			t = i;
		}
		if (t + 1 < n && q + a[t + 1] <= p)
			y++;
		int res = max(x, y);
		cout << res << endl;
	}
}