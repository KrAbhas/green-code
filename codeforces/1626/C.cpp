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
		vector<int> b(n);
		vector<pair<int,int>> c(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < n; i++) {
			b[i] = a[i] - b[i] + 1;
			c[i] = {a[i], b[i]};
		}
		int dp[n] = {0};
		sort(all(c));
		for (int i = 0; i < n; i++) {
			dp[i] = c[i].second;
			for (int j = 0; j <= i; j++) {
				if (dp[i] <= c[j].first) {
					dp[i] = min(dp[i], dp[j]);
				}
				dp[j] = min(dp[i], dp[j]);
			}
		}
		ll ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (dp[i] != dp[i + 1])
				ans += f(c[i].first - dp[i] + 1);
		}
		ans += f(c[n - 1].first - dp[n - 1] + 1);
		cout << ans << endl;
	}
	return 0;
}       	

