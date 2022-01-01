#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e9;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--) {
		ll n, a, b;
		cin >> n >> a >> b;
		if (b == 1){
			cout << "Yes\n";
			continue;
		}
		bool ok = false;
		ll p = 1;
		if (n % b == a)
			ok = true;
		if (a != 1)
			for (int i = 0; p <= n; i++) {
				if (p % b == n % b) {
					ok = true;
					break;
				}
				p *= a;
			}
		if (ok)
			cout << "Yes\n";
		else cout << "No\n";
	}
}