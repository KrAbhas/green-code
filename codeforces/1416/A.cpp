#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const int inf = 1e9;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n; 
		int a;
		vector<vector<int>> v(n + 1);
		vector<pair<int,int>> vp;
		for (int i = 0; i < n; i++) {
			cin >> a;
			v[a].push_back(i);
		}
		for (int i = 1; i <= n; i++) {
			if (v[i].empty())
				continue;
			int t = v[i].size();
			int p = -1;
			int m = 0;
			for (int j = 0; j < t; j++) {
				m = max(m, abs(p - v[i][j]));
				p = v[i][j];
			}
			m = max(m, abs(p - n));
			vp.push_back({m, i});
		}
		sort (all(vp));
		vector<int> vec(n, inf);
		int t = vp.size();
		for (int i = 0; i < t; i++) {
			vec[vp[i].first - 1] = min(vec[vp[i].first - 1], vp[i].second);
		}
		for (int i = 1; i < n; i++) {
			vec[i] = min(vec[i], vec[i - 1]);
		}
		for (int i = 0; i < n; i++) {
			if (vec[i] == inf)
				cout << -1 << " ";
			else cout << vec[i] << " ";
		}
		cout << endl;
	}
}