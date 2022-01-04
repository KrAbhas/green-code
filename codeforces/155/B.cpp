#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
		cin >> a[i].first;
	}
	sort(all(a), greater<pair<int,int>>());
	int k = 1;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i].second;
		k = k - 1 + a[i].first;
		if (k == 0)
			break;
	}
	cout << ans << endl;
}