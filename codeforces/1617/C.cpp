#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, const T& i, T& pos){return b < a? a = b, pos = i, 1: 0;}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		int arr[n + 1] = {0};
		vector<int> a(n);
		vector<int> b;
		vector<int> c;
		for (int i = 0; i <= n; i++) arr[i] = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] <= n) arr[a[i]]++;
		}
		for (int i = 0; i < n; i++) {
			if (arr[i + 1] > 0) {
				arr[i + 1]--;
			} 
			else b.pb(i + 1);
		}
		for (int i = 0; i < n; i++) {
			if (a[i] <= n) {
				if (arr[a[i]] != 0) {
					c.pb(a[i]);
					arr[a[i]]--;
				}
				continue;
			}
			c.pb(a[i]); 
		}
		sort(all(c));
		bool ok = true;
		int ans = 0;
		n = b.size();
		for (int i = 0; i < n; i++) {
			if ((c[i] / 2 - (c[i] % 2 == 0)) < b[i]) {
				ok = false;
				break;
			}
			ans++;
		}
		if (!ok) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}       	

