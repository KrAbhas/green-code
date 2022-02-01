#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
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
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int n = s.length();
		bitset<1000> bs(s);
		int t = bs.count();
		int m = n;
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') a++;
			else b++;
			asnmn(m, a + t - b);
		}
		a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') a++;
			else b++;
			asnmn(m, b + n - t - a);
		}
		cout << m << endl;
	}
}       	
