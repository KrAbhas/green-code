#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t

//---------------dsu-help taken
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
	const intl inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	intl tt;
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	dsu e(n + 1);
	dsu f(n + 1);
	int x, y;
	for (int i = 0; i < m1; i++) {
		cin >> x >> y;
		x--;
		y--;
		e.unite(x, y);
	}
	for (int i = 0; i < m2; i++) {
		cin >> x >> y;
		x--;
		y--;
		f.unite(x, y);
	}
	int c = 0;
	vector<pair<int,int>> vec;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (e.get(j) != e.get(i) && f.get(j) != f.get(i)) {
				c++;
				vec.push_back({i + 1, j + 1});
				e.unite(i, j);
				f.unite(i, j);
			}
		}
	}
	cout << c << endl;
	for (pair<int,int> p: vec) {
		cout << p.first << " " << p.second << endl;
	}
}