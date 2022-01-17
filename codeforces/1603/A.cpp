#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, const T& i, T& pos){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, const T& i, T& pos){return a < b? a = b, pos = i, 1: 0;}
bool my_cmp(pair<int,int>& p1, pair<int,int>& p2) {
	if(p1.second < p2.second) return true; 
    if(p1.second == p2.second) return p1.first < p2.first; 
    return false; 
}

ll f(ll k) {
	return k * (k + 1) / 2;
}

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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll lcm = 1;
		bool ok = true;
		for (int i = 0; i < n; i++) {
			lcm = lcm * (i + 2) / __gcd(lcm, (ll)(i + 2));
			if (a[i] % lcm == 0) {
				cout << "No\n";
				ok = false;
				break;
			} 
		}
		if (ok)
			cout << "Yes\n";
	}
	return 0;
}       	

