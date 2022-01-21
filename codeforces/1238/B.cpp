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

const ll maX = 1e4 + 7;

long long power(long long x, long long y, long long p) 
{ 
    long long res;
    return res; 
} 


int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--) {
		int n, r;
		cin >> n >> r;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int c = 0;
		int k = 0;
		sort(all(a));
		vector<int> v;
		v.pb(a[0]);
		for (int i = 0; i < n; i++) {
			if (a[i] != v.back())
				v.pb(a[i]);
		}
		int rt = (int)v.size() - 1;
		for (int i = rt; i >= 0; i--) {
			if (v[i] <= k) {
				break;
			}
			k += r;
			c++;
		}
		cout << c << endl;
	}
}       	

