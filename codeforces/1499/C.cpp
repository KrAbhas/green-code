#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)

const int N = 2e5 + 5;
int ans[N];

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> b;
		b.pb(0);
		int p = n, q = n;
		ll ans = (a[0] + a[1]) * 1LL * n;
		int odm = a[1];
		int evm = a[0];
		ll sm = a[0] + a[1];
		for (int i = 2; i < n; i++) {
			sm += a[i];
			if (i & 1) {
	                	odm = min(odm, a[i]);
				--q;
			} 
			else {
	                	evm = min(evm, a[i]);
				--p;
			}
			ans = min(ans, sm - odm - evm + 1LL * odm * q + 1LL * evm * p);
		}
		
		cout << ans << endl;
	}
	return 0;
}       	