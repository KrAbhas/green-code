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
typedef pair<int, int> pi;

const ll maX = 998244353;

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
		int n, m, x;
		cin >> n >> m >> x;
		//vector<int> arr(n);
		int a;
		priority_queue<pi, vector<pi>, greater<pi>> pq;
		for(int i = 0; i < m; i++) {
			pq.push({0, i + 1});
		}
		vector<int> v;
		for (int i = 0; i < n; i++) {
			cin >> a;
			a += pq.top().first;
			int k = pq.top().second;
			pq.pop();
			pq.push({a, k});
			v.pb(k);
		}
		int k = v.size();
		cout << "YES\n";
		for (int i = 0; i < k; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
}       	

