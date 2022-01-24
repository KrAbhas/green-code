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
		int n, k, d;
		cin >> n >> k >> d;
		unmap<int,int> arr;
		int x;
		int c = 0;
		vector<int> a;
		for (int i = 0; i < n; i++) {
			cin >> x;
			a.pb(x);
		}
		int l = 0, r = 0;
		int unique = 0; int m = 0;
		for (int i = 0; i < d; i++) {
			if (arr[a[i]] == 0) {
				unique++;
			}
			arr[a[i]]++;
		}
		m = unique;
		for (int i = d; i < n; i++) {
			if (arr[a[i]] == 0) {
				unique++;
			}
			arr[a[i]]++;
			arr[a[l]]--;
			if (arr[a[l]] == 0) {
				unique--;
			}
			l++;
			asnmn(m, unique);
		}
		cout << m << endl;
	}
}       	

