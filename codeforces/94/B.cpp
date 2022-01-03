#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[6][6];
	int n;
	cin >> n;
	memset(arr, 0, sizeof(arr));
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	for (int i = 1; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			for (int k = j + 1; k < 6; k++) {
				if (arr[i][j] == arr[j][k] && arr[j][k] == arr[k][i] && arr[k][i] == arr[i][j]) {
					cout << "WIN\n";
					return 0;
				}
			}
		}
	}
	cout << "FAIL\n";
}