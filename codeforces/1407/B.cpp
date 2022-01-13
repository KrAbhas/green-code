#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		vector<int> b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<bool> c(n, true);
		ll gcd = 0;
		for (int i = 0; i < n; i++) {
			int k = 0;
			ll p = 0;
			for (int j = 0; j < n; j++) {
				if (c[j]) {
					if (__gcd(a[j], gcd) > p) {
						p = __gcd(a[j], gcd);
						k = j;
					}
				}
			}
			c[k] = false;
			b[i] = a[k];
			gcd = p;
		}
		for (int i = 0; i < n; i++) cout << b[i] << " ";
		cout << endl;
	}	
	return 0;
}       	