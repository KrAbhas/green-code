#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, const T& i, T& pos){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, const T& i, T& pos){return a < b? a = b, pos = i, 1: 0;}

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
		int l = 0; int r  = n - 1;
		int alice = 0, bob = 0;
		alice = a[0];
		l = 1;
		int i = 1;
		int c = 1;
		int ta = 0, tb = 0;
		bool ok = true;
		ta += a[0];
		while (l <= r) {
			ok = false;
			if (i & 1) {
				bob += a[r];
				tb += a[r];
				r--;
				if (bob > alice) {
					i++;
					alice = 0;
					c++;
					ok = true;
				}
			}
			else {
				alice += a[l];
				ta += a[l];
				l++;
				if (alice > bob) {
					i++;
					bob = 0;
					c++;
					ok = true;
				}
			}
		}
		if (!ok) c++;
		cout << c << " " << ta << " " << tb << endl;
	}
	return 0;
}       	

