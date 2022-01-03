#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int x, y;
	vector<vector<int>> v(6);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i < 6; i++) {
		if (v[i].size() >= 3 || 4 - v[i].size() >= 3) {
			cout << "WIN\n";
			return 0;
		}
	}
	cout << "FAIL\n";
}