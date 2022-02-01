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

#define PI 3.14159265
int maX = 1e6 + 1;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	unmap<char, int> dir;
	dir['N'] = 1;
	dir['S'] = -1;
	dir['E'] = 1;
	dir['W'] = -1;
	cin >> tt;
	while (tt--) {
		set<pair<pi,pi>> st;
		string s;
		cin >> s;
		int x = 0;
		int y = 0;
		int c = 0;
		for (char ch: s) {
			int a = x, b = y;
			if (ch == 'N' || ch == 'S') {
				y += dir[ch];
			}
			else x += dir[ch];
			if (st.count({{a, b},{x, y}})) {
				c++;
			}
			else {
				st.insert({{a, b},{x, y}});
				st.insert({{x, y}, {a, b}});
				c += 5;
			}
		}
		cout << c << endl;
	}
}       	
