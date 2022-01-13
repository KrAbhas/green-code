#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
template<class T> bool asnmax (T& a, const T& b){return a < b? a = b, 1: 0;} 

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(all(a));
		vector<int> cnt; cnt.pb(1);
		int mx = 0;
		int r = 0;
		for (int i = 1; i < n; i++) {
	        	if (a[i - 1] != a[i]) asnmax(mx, cnt.back()), r++, cnt.pb(1);
			else cnt[r]++;
		}
		asnmax(mx, cnt.back());
		cout << (2 * mx >= n? abs(n - 2 * mx): (n % 2)) << endl;
	}	
	return 0;
}       	