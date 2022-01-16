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
	int lim = 2 * 1e5;
	vector<vector<int>> pref(30, {0});
	for (int i = 0; i < 30; i++) {
		for (int j = 1; j <= lim; j++) {
			pref[i].pb(pref[i][j - 1] + (((1 << i) & j) != 0));
		}
	}
	int tt;
	cin >> tt;
	while(tt--) {
		int l,r;
		cin >> l >> r;
		vector<int> b;
		for (int i = 0; i < 30; i++) {
			b.pb(r - l + 1 - pref[i][r] + pref[i][l - 1]);
		}
		sort(all(b));
		cout << b[0] << endl;
	}
	return 0;
}       	

