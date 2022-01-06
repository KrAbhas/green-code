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
	int n, m, k;
	cin >> n >> m >> k;
	ll a[m + 1];
	for (int i = 0; i <= m; i++) {
		cin >> a[i]; 
	}
	ll r;
	int res = 0;
	for (int i = 0; i < m; i++) {
		r = a[i] ^ a[m];
		int c = 0;
		while (r != 0) {
			r = r & (r - 1);
			c++;
		}
		if (c <= k)
			res++;
	}
	cout << res << endl;
}