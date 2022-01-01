#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const int inf = 1e9;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--) {
		ll n;
		cin >> n;
		ll a, b, c;
		a = 2, b = 2, c = 2;
		for (int i = 2; n / (i * (i + 1)) > i + 1; i++) {
			a = i;
			for (int j = i + 1; (n / (i * j)) > j; j++) {
				c = n / (i * j);
				b = j;
				if (i * j * c == n && c > i && c > j) {
					break;
				}	
			}
			if (a * b * c == n && c > a && c > b)
				break;
		}
		if (a * b * c == n && c > a && c > b)
			cout << "YES\n" << a << " " << b << " " << c << endl;
		else cout << "NO\n";
	}
}