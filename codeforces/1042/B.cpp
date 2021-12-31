#include<bits/stdc++.h>
using namespace std;

//think if using inf, it may cause overflow or underflow

#define ll long long
#define intl int64_t

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	intl inf = 3 * (1e5 + 1);
	ll n;
	cin >> n;
	intl c = 0; string s;
	intl arr[3] = {2, 1, 0};
	vector<vector<intl>> dp(8, vector<intl> (n + 1, inf));
	for (intl i = 0; i < n; i++) {
		cin >> c >> s;
		intl m = 0;
		for (char ch: s) {
			m = m | (1 << arr[ch - 'A']);
		} 
		dp[m][i + 1] = min(dp[m][i], c);
		for (intl j = 0; j < 8; j++) {
			dp[j][i + 1] = min(dp[j][i + 1], dp[j][i]);
			dp[(m | j)][i + 1] = min(c + dp[j][i], dp[(m | j)][i + 1]);
		}
	}
	
	intl res = dp[7][n];
	if (res >= inf)
		cout << -1 << endl;
	else 
		cout << res << endl;
}