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
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;

const ll maX = 998244353;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--) {
		ll n;
		cin >> n; 
		ll k;
		cin >> k;
		vector<int> a(n);
		for (ll i = 0; i < n; i++) cin >> a[i];
		ll t = 0;
		map<int,pi> um;
		for (ll i = 0; i < n; i++) {
			ll p = ceil(a[i] * 1.0 / k) * k - a[i];
			um[p].first++;
			asnmx(um[p].second, a[i]);
			if (p != 0)
				asnmx(t, p);
		}
		ll s = 0;
		map<int,pi>::iterator it;
		for (it = um.begin(); it != um.end(); it++) {
			ll p = it->first;
			ll q = it->second.first;
			if (p != 0)
				asnmx(s, (p + (q - 1) * k) + 1);
		}
		cout << s << endl;
	}
}       	
