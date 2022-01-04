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
	int n, m;
	cin >> n >> m;
	n -= 5;
	int t = 0;
	while (n > 0) {
		cout << 4;
		n -= 4;
		t++;
	}
	cout << 5;
	cout << endl;
	for (int i = 0; i <= t; i++)
		cout << 5;
	cout << endl;
}