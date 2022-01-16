#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, const T& i, T& pos){return b < a? a = b, pos = i, 1: 0;}

ll ap(ll k) {
	return k * (k + 1) / 2;
}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while(tt--) {
		ll k, x;
		cin >> k >> x;
		ll half = ap(k);
		ll full = ap(k - 1);
		if (half + full <= k) {
			cout << (2LL * k - 1) << endl;
			continue;
		}
		ll ans = 0;
		if (half < x) {
			x = x - half;
			ans += k;
			x = full - x;
		}
		ll l = 0; ll r = k + 1;		
		while (l + 1 < r) {
			ll m = (l + r) / 2LL;
			if (ap(m) <= x) {
				l = m;
			}
			else r = m;
		}
		if (ans == 0) {
			ans = l + ans + (ap(l) < x);
		}
		else {
			ans += (k - 1 - l);
		}
		cout << ans << endl;
	}
	return 0;
}       	

