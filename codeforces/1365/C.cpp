#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
// use for unordered map (for high collison):
// um.reserve(4096);
// um.max_load_factor(0.25);
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;

int maX = 1e6 + 1;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n; 
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		b[x] = i + 1;
	}
	unmap<int,int> uml;
	uml.reserve(4096);
	uml.max_load_factor(0.25);
	for (int i = 1; i <= n; i++) {
		if (a[i] >= b[i]) {
			uml[a[i] - b[i]]++;
		}
		else {
			uml[n - b[i] + a[i]]++;
		}
	}
	int m = 0;
	for (auto [p, q]: uml) {
		asnmx(m, q);
	}
	cout << m << endl;
}       	
