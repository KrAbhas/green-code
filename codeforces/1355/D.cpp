#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
// use for unordered map (for high collison):
// um.reserve(4096);
// um.max_load_factor(0.25);
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;

int maX = 1e6 + 1;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	int t = s - n + 1;
	int p = t - n + 1;
	if (p >= 1 && s % 2 == 0 || p >= 2 && s % 2 == 1) {
		cout << "YES\n";
		for (int i = 0; i < n - 1; i++) {
			cout << 1 << ' ';
		}
		cout << t << endl;
		cout << s / 2 << endl;
	}
	else cout << "NO\n";
}       	
