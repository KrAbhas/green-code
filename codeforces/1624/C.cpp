//11.01.2022 13:13:09
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
		vector<bool> b(n + 1, false);
		sort(a.begin(), a.end());
		bool ok = false;
		for (int i = 0; i < n; i++) {
			ok = false;
			while (a[i] >= 1) {
	                	if (a[i] <= n) {
	                        	if (b[a[i]] == false) {
					 	b[a[i]] = true;
						ok = true;
						break;
	                        	}
	                	}
				a[i] /= 2;
			}
			if (!ok)
				break;
		}
		if (!ok)
			cout << "No\n";
		else cout << "Yes\n";
	}
}