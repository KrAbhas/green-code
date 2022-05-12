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
const int maxx = 1e5 + 10;
const int mn = 1025;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll s = 0;
	int c = 0;
	for (int i = 0; i < n; i++) {
		s += a[i];
		pq.push(a[i]);
		while (!pq.empty() && s < 0) {
			s -= pq.top();
			pq.pop();
		}
	}
	cout << sz(pq) << endl;
}