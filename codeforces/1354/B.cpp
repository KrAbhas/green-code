#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const int inf = 1e9;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int n = s.length();
		vector<vector<int>> dp(8, vector<int> (n + 1, inf));
		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			int m = 0;
			m = 1 << (s[i] - '1');
			for (int j = 0; j < 8; j++) {
				dp[j][i + 1] = min(dp[j][i + 1], dp[j][i] + 1);
				dp[m][i + 1] = 1;
				dp[(m | j)][i + 1] = min(dp[j][i] + 1, dp[(m | j)][i + 1]); 
			}
		}
		int m = inf;
		for (int i = 1; i <= n; i++) {
			m = min(m, dp[7][i]);
		}
		if (m == inf)
			cout << 0 << endl;
		else cout << m << endl;
	}
}