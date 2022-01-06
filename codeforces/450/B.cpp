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
	ll x, y;
	cin >> x >> y;
	ll n;
	cin >> n;
	n--;
	ll arr[6];
	arr[0] = x;
	arr[1] = y;
	for (int i = 2; i < 6; i++) {
		arr[i] = arr[i - 1] - arr[i - 2];
	}
	n = n % 6;
	ll mod = (1e9 + 7);
	ll a = arr[n];
	ll b = mod;
	if (arr[n] < 0)
		cout << ((b + (a%b)) % b) << endl;
	else cout << (a % b) << endl;
}