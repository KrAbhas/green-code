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
		int arr[n];
		cin >> arr[0];
		int a = -1;
		for (int i = 1; i < n; i++) {
			cin >> arr[i];
			if (arr[i - 1] == 0 && arr[i] == 1) {
				a = i;
			}
		}
		if (arr[0] == 1) {
			cout << n + 1 << " ";
			for (int i = 1; i <= n; i++) {
				cout << i << " ";
			}	
		}
		else if (a == -1) {
			for (int i = 1; i <= n + 1; i++) {
				cout << i << " ";
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (i == a) {
					cout << (n + 1) << " ";
				}
				cout << (i + 1) << " ";
			}
		}
		cout << "\n";
	}
}