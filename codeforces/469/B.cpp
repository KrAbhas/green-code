#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p, q, l, r;
	cin >> p >> q >> l >> r;
	bool aval[1001] = {false};
	int x, y;
	for(int i = 0; i < p; i++) {
		cin >> x >> y;
		for (int j = x; j <= y; j++) {
			aval[j] = true;
		}
	}
	vector<vector<int>> a;
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		a.push_back({x, y});
	}
	bool ok = false;
	int c = 0;
	for (int i = l; i <= r; i++) {
		ok = false;
		for (vector<int> p: a) {
			for (int j = min(p[0] + i, 1000); j <= min(p[1] + i, 1000); j++) {
				if (aval[j])
					ok = true;
				if (ok)
					break;
			}
			if (ok)
				break;
		}
		if (ok)
			c++;
	}
	cout << c << endl;
}