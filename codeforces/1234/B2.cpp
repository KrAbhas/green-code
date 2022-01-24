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
	int n, k;
	cin >> n >> k;
	unmap<int,bool> arr;
	for (int i = 0; i < maX; i++) arr[i] = 0;
	int x;
	int c = 0;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (arr[x]) {
			continue;
		}
		if (c < k) {
			arr[x] = 1;
			c++;
			a.pb(x);
			continue;
		} 
		arr[x] = 1;
		int t = a.size(); 
		arr[a[t - k]] = 0; 
		a.pb(x);
	}
	int t = a.size();
	cout << min(k, t) << endl;
	for (int i = t - 1; i >= t - min(k, t); i--) {
		cout << a[i] << ' ';
	}
	cout << endl;
}       	

