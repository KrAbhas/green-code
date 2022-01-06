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
	int n;
	cin >> n;
	vector<int> a(n);
	int t = n;
	int m = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0 && a[i - 1] > a[i]) {
			t = i;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[(i + t) % n] > a[(i + 1 + t) % n]) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << n - t << endl;
}