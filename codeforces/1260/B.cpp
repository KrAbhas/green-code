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

const int maX = 1e9 + 7;

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
		int n, a, b;
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		int x = b - a;
		if (a == 0 && b == 0) cout << "YES\n";
		else if (a * 2 < b || a == 0 || b == 0) {
			cout << "NO\n";
		}
		else if (a - x == b - 2 * x && (a - x) % 3 == 0 && a - x >= 0) cout << "YES\n";
		else if ((a % 3 == 0 && b % 3 == 0) || a * 2 == b) {
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
}       	

