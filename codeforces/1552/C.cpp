#include<bits/stdc++.h>
using namespace std;

#define ll long long

//if runtime error
//check: div by 0
//check: out of bound

int good(int d, int j, int arr[][5]) {
	int r = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[d][i] > arr[j][i]) {
			r++;
		}
	}
	return r > 2 ? j : d;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		int total = 2 * n + 1;
		int arr[total];
		int dp[total];
		int mark[total];
		int count[total];
		int a, b;
		memset (mark, 0, sizeof(mark));
		memset (arr, 0, sizeof(arr));
		memset (count, 0, sizeof(count));
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			arr[a] = b;
			arr[b] = a;
		}

		dp[0] = 0;
		for (int i = 1; i < total; i++) {
			dp[i] = dp[i - 1];
			if (arr[i] == 0) 
				dp[i] = dp[i - 1] + 1;
			//cout << dp[i] << " ";
		}
		//cout << "\n";

		int res = 0;
		int ans = 0;
		for (int i = 1; i < total; i++) {
			if (arr[i] != 0 && mark[i] != 1) {
				mark[i] = 1;
				mark[arr[i]] = 1;
				a = min(i, arr[i]);
				b = max(i, arr[i]);
				for (int j = a + 1; j < b; j++) {
					if ((arr[j] < a || arr[j] > b) && arr[j] != 0) {
						//cout << j<<"~";
						count[j]++;
						count[arr[j]]++;
						res++;
					}
				}
				res -= count[arr[i]];
				//cout <<i<<":" <<res << " ";
				//red-red done
				ans += min (dp[b] - dp[a], dp[a] + dp[total-1] - dp[b]);
			}
		}
		//cout << endl;
		//cout << res << endl;
		//cout << ans << endl;
		//cout << (dp[total - 1] / 2 * (dp[total - 1] / 2 - 1) / 2) << endl;
		int result = res + ans + (dp[total - 1] / 2 * (dp[total - 1] / 2 - 1) / 2);
		cout << result << "\n";
	}
}

