#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fact(a,b) factorial (a, b)

ll factorial (int k, int s) {
	ll f = 1;
	for (int i = s; i <= k; i++) {
		f *= i;
	}
	return f;
}

ll ncr(int n, int r) {
	int rd = n - r;
	int m = min(r, rd);
	ll nf = fact(n, (rd + 1));
	ll rf = fact((n - m), 1);
	ll ans = nf * 1.0 / rf;
	return ans;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		ll n, m, k;
		cin >> n >> m >> k;
		if (m < n - 1 || m > (n * (n - 1ll) / 2)) {
			cout << "NO\n";
		}
		else if (n == 1 && k > 1) {
			cout << "YES\n";
		}
		else if (m == (n * (n - 1ll) / 2) && k > 2) {
			cout << "YES\n";
		}
		else if (m >= (n - 1) && m < (n * (n - 1ll) / 2) && k > 3) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}
}