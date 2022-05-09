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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<set<int>> v(3);
	vector<int> a(maX);
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x]++;
		if (a[x] >= 8) {
			v[2].insert(x);
		}
		else if (a[x] >= 4) {
			v[1].insert(x); 
		}
		else if (a[x] >= 2) {
			v[0].insert(x);
		}
		if (a[x] < 8 && v[2].find(x) != v[2].end()) {
			v[2].erase(v[2].find(x));
		}
		if ((a[x] >= 8 || a[x] < 4) && v[1].find(x) != v[1].end()) {
			v[1].erase(v[1].find(x));
		}
		if ((a[x] >= 4 || a[x] < 2) && v[0].find(x) != v[0].end()) {
			v[0].erase(v[0].find(x));
		}
		if (a[x] >= 6 && a[x] < 8) {
			v[0].insert(x);
		}
	}
	cin >> n;
	char ch;
	for (int i = 0; i < n; i++) {
		cin >> ch >> x;
		if (ch == '+') {
			a[x]++;
		}
		else a[x]--;
		if (a[x] >= 8) {
			v[2].insert(x);
		}
		else if (a[x] >= 4) {
			v[1].insert(x); 
		}
		else if (a[x] >= 2) {
			v[0].insert(x);
		}

		if (a[x] < 8 && v[2].find(x) != v[2].end()) {
			v[2].erase(v[2].find(x));
		}
		if ((a[x] >= 8 || a[x] < 4) && v[1].find(x) != v[1].end()) {
			v[1].erase(v[1].find(x));
		}
		if ((a[x] >= 4 || a[x] < 2) && v[0].find(x) != v[0].end()) {
			v[0].erase(v[0].find(x));
		}
		if (a[x] >= 6 && a[x] < 8) {
			v[0].insert(x);
		}

		if (sz(v[2]))
			cout << "YES";
		else if (sz(v[1]) > 1)
			cout << "YES";
		else if (sz(v[1]) == 1 && sz(v[0]) > 1) {
			cout << "YES";
		}
		else cout << "NO";
		cout << endl;
	}
}