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

const ll maX = 2 * 1e5 + 7;

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
		int s, b, e;
		cin >> s >> b >> e;
		if (s + e <= b) {
			cout << 0 << endl;
			continue;
		}
		if (s <= b) {
			e = e - (b - s + 1);
			s = b + 1;
		}
		int l = -1; int r = e;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			if (s + m <= e + b - m)
				l = m;
			else r = m;
		}
		cout << e - r + 1 << endl;
	}
}       	

