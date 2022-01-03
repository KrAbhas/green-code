#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const intl inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	intl tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int un[n];
		int k = 0;
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> un[i];
			if (mp[un[i]] == 0) {
				mp[un[i]] = k;
				k++;
			}
		}
		for (int i = 0; i < n; i++) {
			un[i] = mp[un[i]];
		}
		int a;
		vector<intl> m[k + 1];
		for (int i = 0; i < n; i++) {
			cin >> a;
			m[un[i]].push_back(a);
		}
		vector<pair<int,int>> vec;
		for (int i = 0; i <= k; i++) {
			int t = (int)(m[i].size());
			sort(all(m[i]), greater<intl>());
			for (int j = 1; j < t; j++) {
				m[i][j] += m[i][j - 1];
			}
			vec.push_back({t, i});
		}
		sort(all(vec), greater<pair<int,int>>());
		int ok = false;
		for (int i = 1; i <= n; i++) {
			if (ok == true){
				cout << 0 << " ";	
				continue;
			}
			intl s = 0;
			for (int it = 0; it <= k; it++) {
				if (vec[it].first < i) break;
				int j = vec[it].second;
				int t = (int)(m[j].size());
				int x = t % i;
				s += m[j][t - x - 1];
			}
			cout << s << " ";
			if (s == 0)
				ok = true;
		}
		cout << endl;
	}
}