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
	ll tt;
	cin >> tt;
	while (tt--) {
		ll a, b, p;
		cin >> a >> b >> p;
		string ss;
		cin >> ss;
		ll n = ss.length();
		vector<ll> v(n + 1);
		v[n] = 0;
		for (ll i = n - 2; i >= 0; i--) {
			if (ss[i] == 'A') {
				v[i] = v[i + 1] + a;
				i--;
				while (i >= 0 && ss[i] == 'A') {
					v[i] = v[i + 1];
					i--;
				}
			}
			else {
				v[i] = v[i + 1] + b;
				i--;
				while (i >= 0 && ss[i] == 'B') {
					v[i] = v[i + 1];
					i--;
				}
			}
			i++;
		}
		ll k = 0;
		for (ll i = 0; i < n; i++) {
			if (p >= v[i]) {
				k = i;
				break;
			}
		}
		cout << k + 1 << endl;
	}
}       	

