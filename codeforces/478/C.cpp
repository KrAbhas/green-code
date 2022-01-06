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
	ll x, y, z;
	vector<ll> a(3);
	cin >> x >> y >> z;
	a = {x, y, z};
	sort (all(a));
	if (a[2] > 2 * (a[0] + a[1])) {
		x = a[0] + a[1];
	}
	else x = (x + y + z) / 3;
	cout << x << endl;
}