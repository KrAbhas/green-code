#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
// use for unordered map (for high collison) with 2^x:
// um.reserve(4096); um.max_load_factor(0.25);
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
typedef pair<int, int> pi;
 
#define PI 3.14159265
const ll inf = 1e9 + 7;
const int maX = 1e5 + 10;
const int mn = 1025;

ll c = 0;

void mrg(int l, int m, int r, vector<int>& a) {
	vector<int> lt(m - l + 1);
	vector<int> rt(r - m);
	int n1 = m - l + 1;
	int n2 = r - m;
	for (int i = l; i <= m; i++) {
		lt[i - l] = a[i];
	}
	for (int i = m + 1; i <= r; i++) {
		rt[i - m - 1] = a[i];
	}
	int i = 0; int j = 0; int k = l;
	while (i < n1) {
		if (j < n2 && rt[j] <= lt[i]) {
			a[k++] = rt[j++];
			c += m + 1 + j - k;
		}
		else {
			a[k++] = lt[i++];
		}
	}
	while (j < n2) {
		a[k++] = rt[j++];
	}
}

void mrgsrt(int l, int r, vector<int>& a) {
	if (l >= r)
		return;
	int m = (l + r) / 2;
	mrgsrt(l, m, a);
	mrgsrt(m + 1, r, a);
	mrg(l, m, r, a);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		c = 0;
		mrgsrt(0, n - 1, a);
		cout << c << endl;
	}
}