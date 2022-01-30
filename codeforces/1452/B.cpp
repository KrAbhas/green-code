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
typedef pair<ll, ll> pi;

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
		vector<ll> a(n);
		ll s = 0;
		ll m = 0;
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
			asnmx(m, a[i]);
		}
		ll k = s;
		if (s <= m * (n - 1))
			cout << (m * (n - 1) - s) << endl;
		else {
			while (s % (n - 1)) s++;
			cout << s - k << endl;
		}
	}
}       	
