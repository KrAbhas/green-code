#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	vector<bool> row(m, true);
	vector<bool> col(n, true);
	int arr[m][n];
	bool ok = false;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				ok = true;
			row[i] = row[i] & arr[i][j];
			col[j] = col[j] & arr[i][j];
		}
	}
	bool k = false;
	for (int i = 0; i < m; i++) {
		k = k | row[i];
	}
	if (!k && ok){
		cout << "NO\n";
		return 0;
	}
	k = false;
	for (int i = 0; i < n; i++) {
		k = k | col[i];
	}
	if (!k && ok){
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && (!row[i] && !col[j])) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (row[i] && col[j])
				cout << 1 << " ";
			else cout << 0 << " ";
		}
		cout << endl;
	}
}