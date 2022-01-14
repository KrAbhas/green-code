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
		vector<int> a(n);
		int p = 0, q = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 0) p++;
			else q++;
		}
		if (p >= n / 2) {
			cout << n / 2 << endl;
			for (int i = 0; i < n / 2; i++) cout << 0 << ' ';
		}
		else {
			cout << q - (q & 1) << endl;
			for (int i = 0; i < q - (q & 1); i++) cout << 1 << ' ';
		}
		cout << endl;
	}	
	return 0;
}       	