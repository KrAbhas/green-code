#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> arr(26, 0);
		for (int i = 0; i < n; i++) {
			arr[s[i] - 'a']++;
		}
		int c = 0;
		for (int i = 0; i < 26; i++) {
			if (arr[i] % 2 == 1)
				c++;
		}
		int r = (n - c) / 2;
		int p = r / k;
		if ((r % k) * 2 + c >= k)
			cout << p * 2 + 1 << endl;	
		else cout << p * 2 << endl;
	}
}