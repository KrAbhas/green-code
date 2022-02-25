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

int func(int l, int r, char ch) {
	if (l + 1 == r) return s[l] != ch;
	int mid = (l + r) / 2;
	int cntl = 0, cntr = 0;
	for (int i = l; i < r; i++) {
		if (i < mid) {
			cntl += (ch != s[i]);
		}
		else cntr += (ch != s[i]);
	}
	return min(cntr + func(l, mid, ch + 1), cntl + func(mid, r, ch + 1)); 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n;
		cin >> s;
		cout << func(0, n, 'a') << endl;
	}
}