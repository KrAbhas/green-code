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
 
const int maX = 1e5 + 10;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0; int r = n - 1;
	int x = -1, y = -1;
	int p = 0;
	string s = "";
	while (l <= r) {
		if (a[l] < a[r]) {
			if (p < a[l]) {
				p = a[l];
				s.pb('L');
				l++;
			}
			else if (p < a[r]) {
				p = a[r];
				s.pb('R');
				r--;
			}
			else break;
		}
		else if (a[r] < a[l]) {
			if (p < a[r]) {
				p = a[r];
				s.pb('R');
				r--;
			}
			else if(p < a[l]) {
				p = a[l];
				s.pb('L');
				l++;
			}
			else {
				break;
			}
		}
		else {
			x = l;
			y = r;
			break;
		}
	}
	string s1 = "";
	string s2 = "";
	int t = p;
	if (x == -1 && y == -1) {
		cout << (int)(s.length()) << endl<< s << endl;
		return 0;
	}
	if (x != -1) {
		while (p < a[x] && x < n - 1) {
			p = a[x];
			x++;
			s1.pb('L');
		}
		p = t;
	}
	if (y != -1) {
		while (p < a[y] && y >= 0) {
			p = a[y];
			y--;
			s2.pb('R');
		}
	}

	cout << (int)(s.length() + max(s1.length(), s2.length())) << endl;
	if (s1.length() > s2.length()) {
		cout << s << s1 << endl;
	}
	else cout << s << s2 << endl;
}