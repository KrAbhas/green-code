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
	ll tt;
	priority_queue<pi> pq;
	vector<bool> isThere(maX);
	int t = 1;
	int s = 1;
	cin >> tt;
	while (tt--) {
		int n; 
		cin >> n;
		int k;
		if (n == 1) {
			cin >> k;
			pq.push({k, -t});
			isThere[t] = true;
			t++;
		}
		else if (n == 3) {
			while (!isThere[-pq.top().second]) {
				pq.pop();
			}
			int q = -pq.top().second;
			cout << q << ' ';
			pq.pop();
			isThere[q] = false;
			q++;
		}
		else{
			while (!isThere[s]) {
				s++;
			}
			cout << s << ' ';
			isThere[s] = false;
			s++;
		}
	}
}       	
