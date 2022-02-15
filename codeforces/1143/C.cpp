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
 
const int maX = 1e5 + 10;

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<vector<int>> G(n + 1);
	int x, y;
	int root;
	vector<bool> res(n + 1, true);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x == -1) {
			root = i + 1;
		}
		else {
			if (y == 0) {
				a[x]++;
			}
			else{
				res[i + 1] = false;
			}
			G[x].pb(i + 1);
		}
	}
	stack<int> st;
	st.push(root);
	vector<int> ans;
	while(!st.empty()) {
		int k = st.top();
		st.pop();
		for (int i : G[k]) {
			if (!res[i] && a[i] == 0) {
				ans.pb(i);
			}
			st.push(i);
		}
	}
	sort (all(ans));
	if (ans.empty()) {
		cout << -1 << endl;
		return 0;
	}
	for (int i: ans) {
		cout << i << ' ';
	}
	cout << endl;
}