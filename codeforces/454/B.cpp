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
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	int t = 0;
	int m = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i != 0) {
			if (a[i] < a[i - 1]) {
				t++;
				m = i;
				if (a[i] > a[0]) {
					t++;
				}
			}
		}
	}
	if (t != 0 && a[n - 1] > a[0]) {
		t++;
	}
	if (t == 0)
		cout << 0 << endl;
	else if (t == 1){
		cout << n - m << endl;
	}
	else cout << -1 << endl;
}