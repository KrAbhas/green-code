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
		int r = 1;
		int minm = arr[0];
		for (int i = 1; i < n; i++) {
			cin >> arr[i];
			if(arr[i] == arr[i - 1])
				r++;
			minm = min(minm, arr[i]);
		}
		int k = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = abs (arr[i] - minm);
			k = __gcd(arr[i], k);
		}
		if(r == n)
			cout << "-1\n";
		else
			cout << k << endl; 
	}
}