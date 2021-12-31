#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

ll fact (ll n, ll k) {
	ll r = 1;
	for (int i = n; i > n - k; i--) {
		r *= i;
	}
	for (int i = 2; i <= k; i++) {
		r /= i;
	}
	return r;
}

int main(){
	const ll inf = 1e17;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	if (k >= 2) ans += fact(n, 2);
	if (k >= 3) ans += 2 * fact(n, 3);
	if (k >= 4) ans += 9 * fact(n, 4);
	cout << 1 + ans << endl;
}