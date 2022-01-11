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
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		string s;
		cin >> s;
		vector<int> b;
		vector<int> r;
		for (int i = 0; i < n; i++) {
	        	if (s[i] == 'R') r.pb(a[i]);
			else b.pb(a[i]);
		}
	        sort(all(b));
		sort(all(r), greater<int>());
		int n1 = b.size();
		int n2 = r.size();
		int c = 1;
		bool ok = true;
		for (int i = 0; i < n1; i++) {
	        	if (b[i] < c) {
	                	ok = false;
				break;
	        	}
			c++;
		}
		c = n;
		if (ok)
		for (int i = 0; i < n2; i++) {
	        	if (r[i] > c) {
	                	ok = false;
				break;
	        	}
			c--;
		}
		if (!ok) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}       	