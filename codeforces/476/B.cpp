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
const int mn = 1010;
string s1, s2;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int fact[11];
	fact[0] = 1;
	for (int i = 1; i < 11; i++) {
		fact[i] = i * fact[i - 1];
	}
	cin >> s1;
	cin >> s2;
	int p1, p2, m1,m2;
	p1=m1=0;
	int e = 0;
	for (char ch:s1) {
		if (ch == '+') p1++;
		else m1++;
	}
	for (char ch:s2) {
		if (ch == '+') p1--;
		else if (ch == '-') m1--;
		else e++;
	}
	if (p1 < 0 || m1 < 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << setprecision(20) << fact[e] / (fact[p1] * fact[e - p1]) / pow(2, e) << endl;
}