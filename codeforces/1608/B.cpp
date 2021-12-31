#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e17;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--) {
		ll n, a, b;
		cin >> n >> a >> b;
		if (abs(a - b) > 1 || (a + b + 2) > n)
			cout << -1;
		else if ((2 * a >= n || 2 * b >= n))
			cout << -1;
		else {
			int arr[n];
			for (int i = 0; i < n; i++) {
				arr[i] = (i + 1);
			}
			if (a == b) {
				int p = 1;
				while (a--) {
					swap(arr[p], arr[p + 1]);
					p = p + 2;
				}
			}
			else {
				int p;
				if (a < b) {
					p = 0;
					while (b--) {
						swap(arr[p], arr[p + 1]);
						p += 2;
					}
				}
				else {
					p = n - 1;
					while (a--) {
						swap(arr[p], arr[p - 1]);
						p -= 2;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
			}
		}
		cout << endl;
	}
}