#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n;
		vector<int> a(n);
		vector<int> dp(150001, -1);
		int m = INT_MAX;
		pair<int,int> p;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (dp[a[i]] == -1) {
				dp[a[i]] = i;
			}
			else {
				if (m > i - dp[a[i]])
					p = {dp[a[i]], i};
				m = min(m, i - dp[a[i]]);
				dp[a[i]] = i;
			}
		}
		if (m == INT_MAX) cout << -1 << endl;
		else cout << max(n - p.second + p.first, p.first + (n - p.second)) << endl;
	}
}