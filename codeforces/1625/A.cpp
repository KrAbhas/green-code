#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, l;
		cin >> n >> l;
		vector<int> a(l + 1, 0);
		vector<int> b(n);
		ll q = 1 << l;
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			int p = 1;
			int j = 0;
			while (b[i] >= p) {
				a[j] += ((b[i] & p) ? 1 : 0);
				p = p << 1;
				j++;
			}  
		}
		ll x = 0;
		for (int i = 0; i < l; i++) {
			if (a[i] > n / 2) {
				x = (x | (1 << i));
			}
		}
		cout << x << endl;
	}
}