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

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> b(3);
	for (int i = 0; i < 3; i++) cin >> b[i];
	int ans = min ({b[0] / 3, b[1] / 2, b[2] / 2});
	b[0] -= 3 * ans;
	b[1] -= 2 * ans;
	b[2] -= 2 * ans;
	ans *= 7;
	int idx[] = {1, 2, 3, 1, 3, 2, 1};
	int m = 0;
	for (int start = 0; start < 7; start++) {
		vector<int> a = b;
		int i = start;
		int c = 0;
		while (a[idx[i % 7] - 1] != 0) {
			a[idx[i % 7] - 1]--;
			c++;
			i++;
		}
		m = max(m, c);
	}
	cout << m + ans << endl;
}