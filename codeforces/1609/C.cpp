#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, const T& i, T& pos){return b < a? a = b, pos = i, 1: 0;}
//sieve of eratosthenes
const int maX = 1e6 + 1;
bool comp[maX];
inline void sieve() {
	memset(comp, false, sizeof(comp));
	comp[0] = true; comp[1] = true;
	for (int i = 2; i * i < maX; i++) {
		if (!comp[i])
			for (int j = 2 * i; j < maX; j += i) {
				comp[j] = true;
			}
	}
}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	sieve();
	cin >> tt;
	while(tt--) {
		ll n;
		cin >> n;
		int e; cin >> e;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> dpl(n);
		vector<int> dpr(n);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if (i >= e && a[i] == 1) dpl[i] = dpl[i - e] + 1;
			else if (a[i] == 1) dpl[i] = 1;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (i < n - e && a[i] == 1) dpr[i] = dpr[i + e] + 1;
			else if (a[i] == 1) dpr[i] = 1;
		}

		for (int i = 0; i < n; i++) {
			if (!comp[a[i]]) {
				int l = 1;
				int r = 1;
				if (i >= e) l += dpl[i - e];
				if (i < n - e) r += dpr[i + e];
				ans += (ll)l * r - 1;
			}
		}
		cout << ans << endl;
	}	
	return 0;
}       	