#include<bits/stdc++.h>
using namespace std;

#define ll long long

//if runtime error
//check: div by 0
//check: out of bound

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, k;
		cin >> n >> m >> k;
		int p = 0;

		if (n % 2 != 0) {
			n--;
			k -= m / 2;
		}
		if (k < 0) {
			cout << "NO\n";
			continue;
		}
		if (n == 0) {
			if (k != 0)
				cout << "NO\n";
			else cout << "YES\n";
			continue;
		}
		if (k / n > m / 2 || (k / n == m / 2 && k % n != 0)) {
			cout << "NO\n";
			continue;
		}

		int rem = n - (k % n);

		if (rem % 2 == 0 ) {
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
}

