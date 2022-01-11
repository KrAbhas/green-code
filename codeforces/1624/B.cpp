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
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (2 * (b - a) + a == c)
			cout << "Yes\n";
		else if ((2 * (b - a) + a) % c == 0 && (2 * (b - a) + a) > 0)
			cout << "Yes\n";
		else if ((c - a) % 2 == 0 && ((c - a) / 2 + a) % b == 0)
			cout << "Yes\n";
		else if ((b - c + b) % a == 0 && (b - c + b) > 0)
			cout << "Yes\n";
		else cout << "No\n";		
	}
	return 0;
}