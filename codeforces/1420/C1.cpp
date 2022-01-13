#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)

const int N = 2e5 + 5;
int ans[N];

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while(tt--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<long long> mx(n + 1);
		vector<long long> mn(n + 1);
		for (int i = n - 1; i >= 0; i--) {
	        	mx[i] = max(mx[i + 1], a[i] - mn[i + 1]);
			mn[i] = min(mn[i + 1], a[i] - mx[i + 1]); 
		}
		cout << mx[0] << endl;
	}	
	return 0;
}       	