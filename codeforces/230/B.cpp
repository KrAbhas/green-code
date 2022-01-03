#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		ll l = 0; ll r = a;
		while (l + 1 < r) {
			ll m = (l + r) / 2;
			if (m * m <= a)
				l = m;
			else r = m; 
		}
		bool ok = false;
		if (l * l == a) {
			for (ll j = 2; j * j <= l; j++) {
				if (a % j == 0) {
					ok = true;
					break;
				}
			}
			if (ok) 
				cout << "NO\n";
			else
				cout << "YES\n";
		}
		else cout << "NO\n";
	}
}