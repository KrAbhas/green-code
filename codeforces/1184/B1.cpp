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
	int s, b;
	cin >> s >> b;
	vector<int> a(s);
	for (int i = 0; i < s; i++) {
		cin >> a[i];
	}
	vector<pi> vv(b + 1);
	vv[0].first = 0;
	vv[0].second = 0;
	for (int i = 0; i < b; i++) {
		cin >> vv[i].first;
		cin >> vv[i].second;
	}
	sort(all(vv));
	for (int i = 1; i <= b; i++) {
		vv[i].second = vv[i - 1].second + vv[i].second;
	}
	for (int i = 0; i < s; i++) {
		pi pt = {a[i], INT_MAX};
		int pos = upper_bound(vv.begin(), vv.end(), pt) - vv.begin();
		cout << vv[pos - 1].second << ' ';
	}
	cout << endl;
}