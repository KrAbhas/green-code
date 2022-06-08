#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
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
const int maX = 2 * 1e5 + 10;
const int mn = 1025;

void dfs (ll s, map<ll,int> &m) {
	if (m[s]) {
		m[s]--;
		return;
	}
	if (s <= 1)
		return;
	dfs (floor(s / 2.0), m);
	dfs(ceil(s / 2.0), m);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
        vector<ll> a(n);
        ll s = 0;
        for (int i = 0; i < n; i++) {
        	cin >> a[i];
        	s += a[i];
        }
        multiset<ll> p({s});
        multiset<ll> q(a.begin(), a.end());
        while (!p.empty()) {
        	ll x = *--p.end();
        	if (x < *--q.end()) break;
        	p.erase(--p.end());
        	if (q.find(x) != q.end()) 
        		q.erase(q.find(x));
        	else {
        		p.insert(x / 2);
        		p.insert((x + 1) / 2);
        	}
        }
        if (q.empty()) cout << "YES\n";
        else cout << "NO\n";
	}
}