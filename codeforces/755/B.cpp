#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e9;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string str;
	set<string> s;
	for (int i = 0; i < n; i++) {
		cin >> str;
		s.insert(str);
	}
	int t = s.size();
	int c = 0;
	for (int i = 0; i < m; i++) {
		cin >> str;
		s.insert(str);
		if (s.size() == t + 1) {
			t++;
		}
		else c++;
	}
	if (c % 2 != 0) {
		m--;
	}
	if (n > m)
		cout << "YES\n";
	else cout << "NO\n";
}