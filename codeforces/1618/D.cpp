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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		int p = k;
		int t = a[n - 1];
		int c = 0;
		int q = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] == t) c = i;
			else break;
		}
		int s = 0;
		int l = n - k;
		for (int i = n - 2 * k; i < n - k; i++){
			a[i] = a[i] / a[l];
			l++;
		} 
		for (int i = 0; i < n - k; i++) {
			s +=  a[i];
		}
		 cout << s << endl;
	}
	return 0;
}