#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;

const ll maX = 998244353;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, p, k;
		string s;
		int x, y;
		cin >> n >> p >> k >> s >> x >> y;
		vector<int> a(n);
		for (int i = n - 1; i >= 0; i--) {
			a[i] = (s[i] == '0');
			if (i + k < n) {
				a[i] += a[i + k];
			}
		}
		int m = INT_MAX;
		for (int i = 0; i <= n - p; i++) {
			asnmn(m, (i * y) + (x * a[i + p - 1]));
		}
		cout << m << endl;
	}
}       	
