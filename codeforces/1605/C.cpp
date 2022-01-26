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

const ll maX = 998244353;

long long power(long long x, long long y, long long p) 
{ 
    long long res;
    return res; 
} 


int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int m = 10;
		bool ok = false;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'a') {
				if (i + 1 < n && s[i + 1] == 'a') {
					asnmn(m, 2);
					ok = true;
				}
				if (i + 2 < n && s[i + 2] == 'a') {
					ok = true;
					asnmn(m, 3);
				}
				if (i + 3 < n && s[i + 3] == 'a' && s[i + 1] != s[i + 2]) {
					ok = true;
					asnmn(m, 4);
				}
				if (i + 6 < n && s[i + 6] == 'a') {
					int a = 0, b = 0, c = 0;
					for (int j = i; j <= i + 6; j++) {
						if (s[j] == 'a') a++;
						else if (s[j] == 'b') b++;
						else c++;
					}
					if (a > b && a > c) {
						ok = true;
						asnmn(m, 7);
					}
				}
			}
		}
		if (!ok) cout << -1 << endl;
		else cout << m << endl;
	}
}       	

