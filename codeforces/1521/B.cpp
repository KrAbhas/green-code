#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, const T& i, T& pos){return b < a? a = b, pos = i, 1: 0;}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while(tt--) {
		ll n;
		cin >> n;
		vector<int> a(n);
		int m;
		int p = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i == 0) m = a[i];
			asnminpos(m, a[i], i, p);
		}
		cout << n - 1 << endl;
		for (int i = 0; i < n; i++) {
			if (i != p)
				cout << i + 1 << ' ' << p + 1 << ' ' << m + abs(p - i) << ' ' << m << endl; 
		}

	}	
	return 0;
}       	