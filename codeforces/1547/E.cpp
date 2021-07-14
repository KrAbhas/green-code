#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin>> tt;
	while(tt--) {
		int n, k;
		cin>> n>> k;
		int arr[k];
		int x, y;
		ll a[n];
		int c[k];
		for(int i = 0; i < n; i++) a[i] = 2e9;
		for(int i = 0; i < k; i++) cin >> arr[i];
		for(int i = 0; i < k; i++) {
			cin >> c[i];
			arr[i]--;
			a[arr[i]] = c[i];
		}

		vector<ll> ans(n, 2e9);
		ll r = 2e9;
		for(int i = 0; i < n; i++){
			r = min(a[i], r);
			ans[i] = min(r, ans[i]);
			r++;
		}
		

		for(int i = n - 1; i >= 0; i--){
			r = min(a[i], r);
			ans[i] = min(r, ans[i]);
			r++;
		}
		
		for(int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}

		cout << "\n";
	}
}