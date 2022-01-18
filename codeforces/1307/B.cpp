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
template<class T> bool asnminpos (T& a, const T& b, const T& i, T& pos){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, const T& i, T& pos){return a < b? a = b, pos = i, 1: 0;}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, x; 
		cin >> n >> x;
		int a;
		int m = 0;
		bool ok = false;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a == x) ok = true;
			asnmx(m, a);
		}
		if (ok) {
			cout << 1 << endl;
		}
		else if (m > x) {
			cout << 2 << endl;
		}
		else cout << (x / m + ((x % m) != 0)) << endl;
	}
}       	

