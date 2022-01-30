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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> pre(n);
		pre[0] = a[0];
		for (int i = 1; i < n; i++) {
			pre[i] = pre[i - 1] + a[i];
		}
		for (int i = 0; i < n; i++) {
			int s = 0;
			int k = pre[i];
			bool ok = true;
			int c = n;
			for (int j = 0; j < n; j++) {
				s += a[j];
				if (s == k) {
					s = 0;
					c--;
				}
				else if (s > k) {
					ok = false;
					break;
				}
			}
			if (ok && s == 0) {
				cout << c << endl;
				break;
			}
		}
	}
}       	
