#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
#define bit_set_count(x) __builtin_popcountll(x)
// use for unordered map (for high collison) with 2^x:
// um.reserve(4096); um.max_load_factor(0.25);
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}
typedef pair<int, int> pi;
 
#define PI 3.14159265
 
const int maX = 1e9 + 7;

int query(int i) {
	cout << "? " <<i << ' ' << i + 1 << endl;
	fflush(stdout);
	int a;
	cin >> a;
	return a;
}
 
int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[] = {4, 8, 15, 16, 23, 42};
	int a = query(1);
	int b = query(2);
	int c = query(4);
	int d = query(5);
	vector<int> ans;
	vector<bool> vis(1000);
	for (int i = 0; i < 6; i++) vis[arr[i]] = true;
	for (int i = 5; i >= 0; i--) {
		if (a % arr[i] == 0 && vis[a / arr[i]]) {
			ans.pb(arr[i]);
			ans.pb(a / arr[i]);
			break;
		}
	}	
	for (int i = 5; i >= 0; i--) {
		if (b % arr[i] == 0 && vis[b / arr[i]]) {
			if (arr[i] == ans[0] || b / arr[i] == ans[0]) {
				swap(ans[0], ans[1]);
			}
			ans.pb(b / ans[1]);
			break;
		}
	}	
	for (int i = 5; i >= 0; i--) {
		if (c % arr[i] == 0 && vis[c / arr[i]]) {
			ans.pb(arr[i]);
			ans.pb(c / arr[i]);
			break;
		}
	}	
	for (int i = 5; i >= 0; i--) {
		if (d % arr[i] == 0 && vis[d / arr[i]]) {
			if (arr[i] == ans[3] || d / arr[i] == ans[3]) {
				swap(ans[3], ans[4]);
			}
			ans.pb(d / ans[4]);
			break;
		}
	}
	cout << "! ";
	for (int i = 0; i < 6; i++) cout << ans[i] << ' ';
	cout << endl;
	fflush(stdout);
}