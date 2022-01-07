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
		int n;
		cin >> n;
		int arr[3] = {0};
		ll x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			arr[x % 3]++;
		}
		int t = min(arr[1], arr[2]);
		arr[1] -= t;
		arr[2] -= t;
		t += (arr[1] / 3);
		t += (arr[2] / 3);
		cout << t + arr[0] << endl;
	}
}