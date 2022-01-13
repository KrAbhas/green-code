#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		vector<int> a(n); vector<int> b(n);
		for (int i = 0; i < n; i++) {cin >> a[i]; b[i] = a[i];}
		ll s = 0;
		int k = 1;
		int p = 0; 
		for (int i = 1; i < n; i++) {
        	s += abs(a[i] - a[i - 1]);		
		}
		ll mx = max(abs(a[0] - a[1]), abs(a[n - 1] - a[n - 2]));
		for (int i = 1; i < n - 1; i++) {
        	asnmx(mx, (ll)abs(a[i] - a[i + 1]) + abs(a[i - 1] - a[i]) - abs(a[i - 1] - a[i + 1]));
		}
		cout << s - mx << endl;
	}	
	return 0;
}       	