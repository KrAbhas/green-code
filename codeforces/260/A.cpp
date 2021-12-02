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
	string a; ll b, n;
	cin >> a >> b >> n;
	string s = a;
	string str = "";
	//cout << s << endl;
	char ch;
	int p = 0;
	for (int i = 0; i < 10; i++) {
		ch = (char)(i) + '0';
		str = s + ch;
		//cout << str << endl;
		if (stoi(str) % b == 0) {
			s = str;
			p = 1;
			break;
		}
	}
	if (p != 1) {
		cout << "-1\n";
		return 0;
	}
	n--;
	while (n--) {
		s = s + '0';
	}
	cout << s << "\n";
}