#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if (n <= 2) {
		cout << n << endl;
		return 0;
	}
	int l = 2;
	int a, b;
	cin >> a >> b;
	int x;
	int m = 2;
	for (int i = 0; i < n - 2; i++) {
		cin >> x;
		if (x == a + b) {
			l++;
		}
		else {
			m = max(m, l);
			l = 2;
		}
		m = max(m, l);
		a = b;
		b = x;
	}
	cout << m << endl;
}