#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	ll s = 0;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	if (s % 3 != 0){
		cout << 0 << endl;
		return 0;
	}
	s = s / 3;
	vector<int> b(n, 0);
	vector<int> c(n, 0);
	ll t = 0;
	for (int i = 0; i < n - 1; i++) {
		t += a[i];
		if (t == s) {
			b[i + 1] = 1;
		}
	}
	t = 0;
	for (int i = n - 1; i > 0; i--) {
		t += a[i];
		if (i != n - 1) 
			c[i] = c[i] + c[i + 1];
		if (t == s) 
			c[i - 1] += 1;
	}
	ll ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (b[i] == 1) {
			ans += c[i];
		}
	}
	cout << ans << endl;
}