#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a <= b? a = b, pos = i, 1: 0;}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		bool ok = true;
		int m = 0;
		int k = -10;
		int t = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int pref, suf;
		for (int i = 0; i < n; i++) if (a[i] < i) {break;} else {pref = i;}
		for (int i = n - 1; i >= 0; i--) if (a[i] < n - 1 - i) {break;} else suf = i;
		if (pref >= suf) {
			cout << "Yes\n";
		}
		else cout << "No\n";
	}
}       	

