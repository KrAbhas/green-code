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

	int main(){
		const ll inf = 1e18 + 7;
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int tt;
		cin >> tt;
		while (tt--) {
			int n, m;
			int r, c;
			cin >> n >> m;
			cin >> r >> c;
			char arr[n][m];
			bool row = false;
			bool col = false;
			bool white = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cin >> arr[i][j];
					if (arr[i][j] == 'B') white = false;
					if (i == r - 1 && arr[i][j] == 'B') row = true;
					if (j == c - 1 && arr[i][j] == 'B') col = true;
				}
			}
			if (white) {
				cout << -1 << endl;
				continue;
			}
			if (arr[r - 1][c - 1] == 'B')
				cout << 0 << endl;
			else if (row || col) cout << 1 << endl;
			else cout << 2 << endl;
		}
		
	}       	