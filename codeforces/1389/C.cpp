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
const ll inf = 1e9 + 7;
const int maX = 1e5 + 10;
const int mn = 1010;
ll n, k;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		cin >> s;
		n = s.length();
		int ans = 0;
		int dig[10] = {0};
		for (int i = 0; i < n; i++) {
			dig[s[i] - '0']++;
			ans = max(ans, dig[s[i] - '0']);
		}
		for (char i = '0'; i <= '9'; i++) {
			for (char j = '0'; j <= '9'; j++) {
				int m = 0;
				for (int k = 0; k < n; k++) {
					if (s[k] == i) {
						k++;
						while (k < n && s[k] != j) {
							k++;
						}
						if (k != n) {
							m += 2;
						}
					}
				}
				ans = max(ans, m);
			}
		}
		cout << n - ans << endl;
	}
}