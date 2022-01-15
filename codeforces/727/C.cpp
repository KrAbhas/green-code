#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, const T& i, T& pos){return b < a? a = b, pos = i, 1: 0;}
//sieve of eratosthenes
const int maX = 1e6 + 1;
bool comp[maX];
inline void sieve() {
	memset(comp, false, sizeof(comp));
	comp[0] = true; comp[1] = true;
	for (int i = 2; i * i < maX; i++) {
		if (!comp[i])
			for (int j = 2 * i; j < maX; j += i) {
				comp[j] = true;
			}
	}
}

int req(int a, int b) {
	cout << "? " << a + 1 << " " << b + 1 << endl;
	cout.flush();
	int x;
	cin >> x;
	return x;
}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	int n;
	cout.flush();
	cin >> n;
	vector<int> v;
	int x, y, z;
	x = req(0, 1);
	y = req(1, 2);
	z = req(0, 2);
	int t = (x + y + z) / 2;
	v.pb(t - y);
	v.pb(t - z);
	v.pb(t - x);
	for (int i = 3; i < n; i++) {
		t = req(0, i);
		v.pb(t - v[0]);
	}
	cout << "!";
	for (int i = 0; i < n; i++) {
		cout << " " <<v[i];
	}
	cout << endl;
	cout.flush();
	return 0;
}       	