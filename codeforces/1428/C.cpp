#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fact(a,b) factorial (a, b)

ll factorial (ll k, ll s) {
	ll f = 1;
	for (ll i = s; i <= k; i++) {
		f *= i;
	}
	return f;
}

ll ncr(ll n, ll r) {
	ll rd = n - r;
	ll m = min(r, rd);
	ll nf = fact(n, (rd + 1));
	ll rf = fact((n - m), 1);
	ll ans = nf * 1.0 / rf;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		string s;
		cin >> s;
		//cout << s << endl;
		stack<char> str;
		for (char ch : s) {
			if (!str.empty() && ch == 'B' && str.top() == 'A') {
				str.pop();
			}
			else if (!str.empty() && ch == 'B' && str.top() == 'B') {
				str.pop();
			}
			else {
				str.push(ch);
			}
		}
		cout << str.size() << endl;
	}
} 