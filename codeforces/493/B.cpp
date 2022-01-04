#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int x;
	vector<int> p;
	vector<int> m;
	ll s1 = 0;
	ll s2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x < 0) {
			m.pb(-x);
			s1 += -x;
		}
		else { 
			p.pb(x);
			s2 += x;
		}
	}
	if (s2 > s1) {
		cout << "first\n";
		return 0;
	}
	else if (s2 < s1) {
		cout << "second\n";
		return 0;
	}

	int a = p.size();
	int b = m.size();
	for (int i = 0; i < min(a, b); i++) {
		if (m[i] > p[i]) {
			cout << "second\n";
			return 0;
		}
		else if (m[i] < p[i]) {
			cout << "first\n";
			return 0;
		}
	}
	if (a > b) {
		cout << "first\n";
	}
	else if (b > a) {
		cout << "second\n";
	}
	else {
		if (x > 0) {
			cout << "first\n";
		}
		else {
			cout << "second\n";
		}
	}
}