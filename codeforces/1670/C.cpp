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
const int mn = 1010;

template<class T1, class T2> ll power(T1 n, T2 k) {
	ll p = n;
	ll res = 1;
	ll t = 1;
	while (t <= k) {
		if (t & k) {
			res = (res * p) % inf;
		}
		p = (p * p) % inf;
		t = t << 1;
	}
	return res;
}

class dsu {
  public:
  vector<int> p;
  int n;
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		vector<int> d(n);
		for (int i = 0; i < n; i++) 
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		vector<int> c(n);
		for (int i = 0; i < n; i++) {
			cin >> d[i];
			if (d[i])
				c[d[i] - 1] = 1;
		}
		bool ok = 0;
		ll ans = 0;
		dsu gg(n);
		int k = 0;

		for (int i = 0; i < n; i++) {
			if (c[a[i] - 1] || c[b[i] - 1] || a[i] == b[i])
				continue;
			if(!gg.unite(a[i] - 1, b[i] - 1))
				k++;
		}
		ans = power(2, k);
		cout << ans << endl;
	}
}