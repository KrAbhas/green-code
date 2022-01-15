#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, const T& i, T& pos){return b < a? a = b, pos = i, 1: 0;}


int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int,int>> arr;
		if (n == 1) {
			arr = {{0,0}, {0, m - 1}};
		}
		else if (m == 1){
			arr = {{0,0}, {n - 1, 0}};
		}
		else
			arr = {{0,0}, {0, m - 1}, {n - 1, 0}, {n - 1, m - 1}};
		int k = arr.size();
		vector<int> a;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int mx = 0;
				for(int p = 0; p < k; p++) {
					asnmx(mx, abs(i - arr[p].first) + abs(j - arr[p].second));
				}
				a.pb(mx);
			}
		}
		sort(all(a));
		int t = m * n;
		for (int i = 0; i < t; i++) cout << a[i] <<' ';
		cout << endl;
	}
	
}       	