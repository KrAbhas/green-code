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
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		--a[i];
	}
	int ans = 0;
	int ctr = 0;
	for (int i = 0; i < m; ) {
		int j = i;
		ll pg = (a[i] - ctr) / k;
		int d = 0;
		while (j < m && pg == (a[j] - ctr) / k) {
			++j;
			++d;
		}
		ctr += d;
		ans++;
		i = j;
	}
	cout << ans << endl;
}