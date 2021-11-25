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
		int n;
		cin >> n;
		char c;
		cin >> c;
		char a;
		int count = 0;
		int x = 0;
		int k = 0;
		for(int i = 0; i < n; i++) {
			cin >> a;
			if (a == c) {
				count++;
				x = i + 1;
			}
			if (n % (i + 1) != 0) {
				k = i + 1;
			}
		}
		if (count == n) {
			cout << "0\n";
		}
		else {
			if (x > n / 2) {
				cout << "1\n";
				cout << x << "\n";
			}
			else {
				cout << "2\n";
				cout << k << " " << n << "\n";
			}
		}
	}
}