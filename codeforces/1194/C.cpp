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
		string s, t, p;
		cin >> s >> t >> p;
		int k = 0;
		bool ok = true;
		int n = t.length();
		int r = s.length();
		int arr[26] = {0};
		for (int i = 0; i < n; i++) {
			if (k < r) {
				if (s[k] == t[i]) {
					k++;
					continue;
				}
			}
			arr[t[i] - 'a']++;
		}
		if (k < r) ok = false;
		for (char i : p) {
			arr[i - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (arr[i] > 0) {
				ok = false;
				break;
			}
		}
		cout << (ok? "YES\n": "NO\n");
	}
}       	

