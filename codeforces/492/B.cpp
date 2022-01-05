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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	int d = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(all(a));
	int m = 0;
	for (int i = 0; i < n; i++) {
		m = max(m, abs(a[i] - d));
		d = a[i];
	}
	if (2 * (a[0] - 0) > m) {
		m = 2 * (a[0] - 0);
	}
	if (2 * (k - a[n - 1]) > m) {
		cout << setprecision(20) <<1.0 * (k - a[n - 1]) << endl;
		return 0;
	}
	cout << setprecision(20) <<(m / 2.0) << endl;
}