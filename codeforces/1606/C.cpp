#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--) {
		ll n, k;
		cin >> n >> k;
		ll arr[n];
		ll a[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			arr[i] = pow(10, arr[i]);
		}

		ll p = 0;
		int t = 0;
		for (int i = 1; i < n; i++) {
		    ll need = arr[i] / arr[i - 1] - 1;
		    //cout << need << endl;
		    if (k >= need) {
		    	p += need * arr[i - 1];
		    	k -= need;
		    	t = i;
		    }
		    else break;
		}
		p += (k + 1) * arr[t];
		cout << p << endl;
	}
}