#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fact(a,b) factorial (a, b)
#define fo(i, a, n) for (int i = a; i < n; i++)
#define fob(i, a, n) for (int i = a; i >= n; i--)

//_____________________________________________________________________________DSU
class dsu {
public:
	vector<int> p;
	int n;
	dsu (int k) : n(k) {
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
//---------------------------------------------------------------------------factorial, ncr
ll factorial (ll k, ll s) {
	ll f = 1;
	for (ll i = s; i <= k; i++) {
		f *= i;
	}
	return f;
}

ll ncr(ll n, ll r) {
	ll rd = n - r;
	ll m = min(r, rd);
	ll nf = fact(n, (rd + 1));
	ll rf = fact((n - m), 1);
	ll ans = nf * 1.0 / rf;
	return ans;
}

//***************************************************************************implement

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll n;
	cin >> n;
	int a;
	int res = 0;
	int arr[] = {4,8,15,16,23,42};
	int sub[7];
	memset(sub, 0, sizeof(sub));
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 4) {
			sub[0]++;
		}
		else {
			int j = 1;
			while (j < 6 && arr[j] != a) {
				j++;
			}
			if (sub[j - 1] > sub[j]) {
				sub[j]++;
			}
			else res++;
		}
	}
	int k = sub[0];
	fo(i, 1, 6) {
		k = min(sub[i], k);
	}
	fo (i, 0, 6) {
		res += (sub[i] - k);
	}
	cout << res << endl;
} 