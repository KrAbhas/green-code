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

const int maX = 1e9 + 7;

long long power(long long x, long long y, long long p) 
{ 
    long long res;
    return res; 
} 


int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		ll n;
		cin >> n;
		vector<ll> a(n);
		ll s = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
		}
		vector<ll> kad;
		kad.pb(a[0]); 
		ll m = a[0];
		vector<ll> dp;
		for (int i = 1; i < n - 1; i++) {
			if (a[i] + kad[i - 1] <= a[i]) {
				kad.pb(a[i]);
			}
			else kad.pb(a[i] + kad[i - 1]);
			asnmx(m, kad.back());
		}
		dp.pb(a[1]);
		asnmx(m, a[1]);
		for (int i = 2; i < n; i++) {
			if (a[i] + dp.back() <= a[i]) {
				dp.pb(a[i]);
			}
			else dp.pb(a[i] + dp.back());
			asnmx(m, dp.back());
		}
		//cout << m << endl;
		if (s > m) cout << "YES\n";
		else cout << "NO\n";
	}
}       	

