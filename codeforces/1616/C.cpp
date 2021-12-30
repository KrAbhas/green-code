#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--){
		int n;
		cin >> n;
		int t = 0;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i > 0 && a[i] != a[i - 1])
				t++;
		}
		if (n == 1 || n == 2) {
			cout << 0 << endl;
			continue;
		}
		int m = INT_MAX;
		if (t > 0) {
			for (int l = 1; l < n - 1; l++) {
				for (int i = 0; i < n - l; i++) {
					int j = i + l;
					int c = 0;
					int l = i - j;
					int d = a[i] - a[j];
					for (int k = 0; k < n; k++) {
						if (a[k] * l == a[i] * l - (i - 1) * d + (k - 1) * d)
							c++;
					}
					m = min(m, n - c);
				}
			}
			cout << m << endl;
		}
		else cout << 0 << endl;
	}
}