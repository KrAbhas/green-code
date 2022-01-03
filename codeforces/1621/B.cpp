#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const intl inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		ll l, r, c;
		ll inf = 1e18;
		ll left = 1e9 + 1, cl = inf;
		ll right = 0, cr = inf;
		ll len = 0, cost = inf;
		for (int i = 0; i < n; i++) {
			cin >> l >> r >> c;
			if (left > l) {
				cl = inf;
				cost = inf;
				left = l;
			}
			if (right < r) {
				cr = inf;
				cost = inf;
				right = r;
			}
			if (left == l) {
				cl = min(c, cl);
			}
			if (right == r) {
				cr = min(c, cr);
			}
			if (left == l && right == r) {
				cost = min(c, cost);
			}
			cout << min(cost, cr + cl) << endl;
		}
	}
}