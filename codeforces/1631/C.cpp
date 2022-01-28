#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)

//sieve of eratosthenes
	const int maX = 1e6 + 1;
	bool comp[maX];
	inline void sieve() {
		memset(comp, false, sizeof(comp));
		comp[0] = true; comp[1] = true;
		for (int i = 2; i * i < maX; i++) {
			if (!comp[i])
				for (int j = 2 * i; j < maX; j += i) {
					comp[j] = true;
				}
		}
	}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		if (n <= 4 && k == n - 1) {
			cout << -1 << endl;
			continue;
		}
		else if (k == n - 1) {
			cout << n - 2 << ' ' << n - 1 << endl;
			cout << 1 << ' ' << n - 3 << endl;
			cout << 0 << ' ' << 2 << endl;
			for (int i = 3; i < n / 2; i++) {
				cout << i << ' ' << n - 1 - i << endl;
			}
			continue;
		}
		int t = k;
		cout << k << ' ' << n - 1 << endl;
		if (k != 0)
			cout << 0 << ' ' << n - 1 - k << endl;
		for (int i = 1; i < n / 2; i++) {
			if (i != k && i != n - 1 - k) {
				cout << i << ' ' << n - 1 - i << endl;
				t += i & (n - 1 - i);
			}
		}
	}
}