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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if (n == 1 && k >= 1){
		cout << 0 << endl;
		return 0;
	}
	if (s[0] != '1' && k > 0) {
		s[0] = '1';
		--k;
	}
	for (int i = 1; i < n; i++) {
		if (k == 0)
			break;
		if (s[i] != '0') {
			s[i] = '0';
			--k;
		}
	}
	cout << s << endl;
}