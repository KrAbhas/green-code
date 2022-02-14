#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
// use for unordered map (for high collison) with 2^x:
// um.reserve(4096); um.max_load_factor(0.25);
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;
 
#define PI 3.14159265
 
//sieve of eratosthenes
int k = 0;
	const int maX = 1e5 + 100;
	int comp[maX];
	inline void sieve() {
		memset(comp, 0, sizeof(comp));
		comp[0] = 1; comp[1] = 1;
		int c = 1;
		for (int i = 2; i * i < maX; i++) {
			if (!comp[i]) {
				for (int j = 2 * i; j < maX; j += i) {
					comp[j] = c;
				}
				comp[i] = c++;
			}
		}
		k = c;
	}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	sieve();
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (comp[i] == 0) {
			for (int j = i; j <= n; j += i) {
				comp[j] = k;
			}
			k++;
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << comp[i] << ' ';
	}
}