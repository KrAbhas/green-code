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
	string s;
	cin >> s;
	int a = 0;
	int b = 0;
	for (char ch: s) {
		if (ch == '1') {
			cout << 1 << " " << a + 1 << endl;
			a = (a + 2) % 4;
		}
		else {
			cout << 2 << " " << b + 1 << endl;
			b = (b + 1) % 4;
		}
	}
}