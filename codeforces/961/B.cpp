#include<bits/stdc++.h>
using namespace std;

//think if using inf, it may cause overflow or underflow

#define ll long long
#define intl int64_t

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	intl n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<intl> pref(n + 1);
	intl s = 0;
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i];
		cin >> tt;
		if (tt == 1)
			s += a[i];
		else pref[i + 1] += a[i];
	}
	intl m = 0;
	for (int i = 0; i < n; i++) {
		int r = min(n , i + k);
		m = max(pref[r] - pref[i], m);
	}
	cout << (s + m) << endl;
}