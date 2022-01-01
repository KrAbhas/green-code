#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const int inf = 1e9;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--) {
		ll x, y;
		ll a, b;
		cin >> x >> y;
		cin >> a >> b;
		ll s = a * abs (x - y);
		if (2 * a < b) {
			s += 2 * a * min (x, y);
		}
		else s += b * min(x, y);
		cout << s << endl;
	}
}