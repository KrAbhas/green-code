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
	ll n;
	cin >> n;
	int arr[n];
	int brr[n];
	int cnt[1001];
	memset (cnt, 0, sizeof(cnt));
	memset (arr, 0, sizeof(arr));
	memset (brr, 0, sizeof(brr));
	for (int i = 0; i < n; i++) {
		cin >> arr[i] >> brr[i];
		cnt[brr[i]]++;
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		if(cnt[arr[i]] < 1 || (cnt[arr[i]] == 1 && brr[i] == arr[i])) c++;
	}
	cout << c << "\n";
// 5
// 1 1
// 1 2
// 2 3
// 3 4
// 4 3

//output: 0
//expected: 1
}