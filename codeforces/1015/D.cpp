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
	ll n, k, s;
	cin >> n >> k >> s;
	if (k * (n - 1) < s || s < k) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	bool t = false;
	while (s > n - 1) {
		if (k > s - n + 2)
			break;
		s -= n - 1;
		if(t)
			cout << 1 << " ";
		else cout << n << " ";
		t ^= true;
		k--;
	}
	if (k > 1) {
		if (!t) {
			t = true;
			while (k != 1) {
				if (t)
					cout << 2 << " ";
				else cout << 1 << " ";
				s--;
				k--;
				t ^= true;
			}
			if (t)
				cout << 1 + s << endl;
			else cout << 2 + s << endl;
		}
		else {
			t = true;
			while (k != 1) {
				if (t)
					cout << n - 1 << " ";
				else cout << n << " ";
				s--;
				k--;
				t ^= true;
			}
			if (t)
				cout <<  n - s << endl;
			else cout << n - 1 - s << endl;
		}
	}
	else if (!t)
		cout << 1 + s << endl;
	else cout << n - s << endl;
}