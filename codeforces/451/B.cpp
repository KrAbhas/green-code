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
	int n;
	cin >> n;
	int arr[n];
	int srr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		srr[i] = arr[i];
	}
	sort (srr, srr + n);
	int l = 0; int r = n - 1;
	//cout << l << r << endl;
	while (l < n && arr[l] == srr[l]) {
		l++;
	}
	while (r >= 0 && arr[r] == srr[r]) {
		//cout << arr[r] << srr[r] << endl;
		r--;
	}
	//cout << l << r << endl;
	if (l > r) {
		cout << "yes\n";
		cout << "1 1\n";
		return 0;
	}
	int j = l;
	for (int i = r; i >= l; i--) {
		if (arr[i] == srr[j]){
			j++;
		}
		else{
			cout << "no\n";
			return 0;
		}
	}
	cout << "yes\n";
	cout << (l + 1) << " " << (r + 1) << "\n";
}