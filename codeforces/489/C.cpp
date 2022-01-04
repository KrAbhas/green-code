#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, s;
	cin >> m >> s;
	if (s == 0) {
		if (m != 1)
			cout << "-1 -1\n";
		else cout << "0 0\n";
		return 0;
	}
	vector<int> a(m, 0);
	a[m - 1] = 1;
	--s;
	for (int i = 0; i < m; i++) {
		if (s >= 9) {
			a[i] += 9;
		}
		else a[i] += s;
		s -= 9;
		s = max(0, s);
		if (s == 0)
			break; 
	}
	if (a[m - 1] > 9)
		cout << "-1 -1\n";
	else {
		for (int i = m - 1; i >= 0; i--) 
			cout << a[i];
		cout << " ";
		sort(all(a));
		for (int i = 0; i < m; i++) {
			if (i < m - 1 && a[i] == 1 && a[i + 1] != 9) {
				a[i] = 0;
				a[i + 1]++;
			}
		}
		for (int i = m - 1; i >= 0; i--) 
			cout << a[i];
		cout << endl;
	}
}