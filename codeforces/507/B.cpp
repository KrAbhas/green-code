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
	ll r;
	ll x, y, xn, yn;
	cin >> r;
	cin >> x >> y >> xn >> yn;
	
	ll a = (xn - x) * (xn - x);
	ll b = (yn - y) * (yn - y);
	ll c = ceil(sqrt(a + b) / (2 * r));
	
	cout << c << endl;
}