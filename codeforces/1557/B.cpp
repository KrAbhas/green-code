#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fact(a,b) factorial (a, b)
#define loop(i,n) for(i; i < n; i++)

ll factorial (int k, int s) {
	ll f = 1;
	for (int i = s; i <= k; i++) {
		f *= i;
	}
	return f;
}

ll ncr(int n, int r) {
	int rd = n - r;
	int m = min(r, rd);
	ll nf = fact(n, (rd + 1));
	ll rf = fact((n - m), 1);
	ll ans = nf * 1.0 / rf;
	return ans;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n, k;
		cin >> n >> k;
		pair<int,int> arr[n];
		int c = 1;
		for(int i = 0; i < n; i++) {
			cin >> arr[i].first;
			arr[i].second = i;
		}
		sort(arr, arr + n);
		for(int i = 1; i < n; i++) {
			if (arr[i - 1].second + 1 != arr[i].second)
				c++;
		}
		cout << (c <= k ? "Yes\n" : "No\n");
	}
}