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
const int maxx = 2 * 1e5 + 10;
const int mn = 1010;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1; 
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int c = 0; int b = 0;
		int d = 0;
		for (int i = 0; i < n; i += 2) {
			if (a[i] % 2 == 1)
				c++;
			else d++;
			b++;
		}
		if (d != 0 && d != b){
			cout << "NO\n";
			continue;
		}
		c = b = d = 0;
		for (int i = 1; i < n; i+= 2) {
			if (a[i] % 2 == 1)
				c++;
			else d++;
			b++;
		}
		if (d != 0 && d != b) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
}