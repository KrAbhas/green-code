#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
// use for unordered map (for high collison):
// um.reserve(4096);
// um.max_load_factor(0.25);
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;

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

	bool isNotPrime(int k) {
		if (k < maX) return comp[k];
		for (int i = 2; i * i <= k; i++) {
			if (k % i == 0) return true;
		}
		return false;
	}
int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	sieve();
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int k = n;
		if (k == 1) {
			cout << "FastestFinger\n";
			continue;
		}
		if (k % 2 == 1 || k == 2) {
			cout << "Ashishgup\n";
			continue;
		}
		while (k % 2 == 0) {
			k = k / 2;
		}
		if (k == 1) {
			cout << "FastestFinger\n";
		}
		else {
			if (n / k != 2 || isNotPrime(k))
				cout << "Ashishgup\n";
			else {
				cout << "FastestFinger\n";
			}
		}
	}
}       	
