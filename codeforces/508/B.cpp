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
	ll n;
	string s;
	cin >> s;
	n = s.length();
	int p = -1;
	for (int i = 0; i < n; i++) {
		if ((int)(s[i] - '0') % 2 == 0) {
			p = i;
			if (s[i] < s[n - 1]) {
				break;
			}
		}
	}
	if (p == -1)
		cout << p << endl;
	else {
		swap(s[p], s[n - 1]);
		cout << s << endl;
	}
}