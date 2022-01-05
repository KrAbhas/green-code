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
	int n, m;
	cin >> n >> m;
	if (2 * n < m - 2 || n > m + 1) {
		cout << -1 << endl;
		return 0;
	}
	vector<bool> vec;
	while (m > 0) {
		vec.pb(true);
		m--;
		if (m == 0)
			break;
		vec.pb(true);
		m--;
		if (m == 0)
			break;
		vec.pb(false);
		n--;
	}
	if (n != 0){
		vec.pb(false);
		n--;
	}
	if (n != 0) {
		cout << false;
		n--;
	}
	int t = vec.size();
	for (int i = 0; i < t; i++) {
		cout << vec[i];
		if (n != 0 && i < t - 1 && vec[i] & vec[i + 1]) {
			cout << false;
			n--;
		}
	}
	cout << endl;
}