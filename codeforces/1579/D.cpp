#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--) {
		ll n;
		cin >> n;
		set<pair<int,int>> st;
		int a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			st.insert({-a, i + 1});
		}
		vector<pair<int,int>> v;
		while(st.size() > 1) {
			pair<int,int> x = *st.begin();
			st.erase(st.begin());
			pair<int,int> y = *st.begin();
			st.erase(st.begin());
			if (x.first == 0 || y.first == 0)
				break;
			v.push_back({x.second, y.second});
			++x.first;
			++y.first;
			if (x.first != 0)
				st.insert(x);
			if (y.first != 0)
				st.insert(y);
		}
		cout << v.size() << endl;
		for (pair<int,int> p: v) {
			cout << p.first << " " << p.second << endl;
		}
	}
}