#include<bits/stdc++.h>
using namespace std;

#define ll long long

//if runtime error
//check: div by 0
//check: out of bound

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--) {
		int m; 
		cin >> m;
		int arr[2][m];
		int a, b;
		a = 0; b = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				if (j > 0) {
					arr[i][j] += arr[i][j - 1];
				}
			}
		}
		int k = 0;
		int r = 999999999;
		for (int i = 0; i < m; i++) {
			int a = arr[0][m - 1] - arr[0][i];
			if (i > 0)
				k = arr[1][i - 1];
			r = min (r, max (k, a));
		}

		cout << r << "\n";
	}
}

