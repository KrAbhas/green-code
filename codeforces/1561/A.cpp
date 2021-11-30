#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fact(a,b) factorial (a, b)

ll factorial (ll k, ll s) {
	ll f = 1;
	for (ll i = s; i <= k; i++) {
		f *= i;
	}
	return f;
}

ll ncr(ll n, ll r) {
	ll rd = n - r;
	ll m = min(r, rd);
	ll nf = fact(n, (rd + 1));
	ll rf = fact((n - m), 1);
	ll ans = nf * 1.0 / rf;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		ll ans = 0;
		vector<int> vec;
		int a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			vec.push_back(a);
		}
		while (!is_sorted(vec.begin(), vec.end())) {
			//cout << ans;
			ans++;
			if (ans % 2 == 1) {
				for (int i = 0; i < n - 1; i += 2) {
					if(vec[i] > vec[i + 1])
						swap(vec[i], vec[i + 1]);
				}
			}
			else {
				for (int i = 1; i < n; i += 2) {
					if(vec[i] > vec[i + 1])
						swap(vec[i], vec[i + 1]);
				}
			}
		}
		cout << ans;
		cout << "\n";
	}
}