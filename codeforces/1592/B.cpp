#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n, x;
		cin >> n;
		cin >> x;
		int arr[n];
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			ar[i] = arr[i];
		}
		int p = 1;
		sort (arr, arr + n);
		for (int i = 0; i < n; i++) {
			if (ar[i] == arr[i]) {
				continue;
			}
			else if(i + 1 + x > n && i + 1 - x < 1) {
				cout << "NO\n";
				p = 0;
				break;
			}
		}
		if (p == 1) {
			cout << "YES\n";
		}
	}
}