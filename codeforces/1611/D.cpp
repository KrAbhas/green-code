#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)

const int N = 2e5 + 5;
int ans[N];

bool dfs(vector<vector<int>>& g, int root, vector<int>& dis) {
	int n = g[root].size();
	bool k = false;
	for (int i = 0; i < n; i++){
		if (dis[root] > dis[g[root][i]])
			return true;
		k = k | dfs(g, g[root][i], dis);
		ans[g[root][i]] = dis[g[root][i]] - dis[root];
	}	
	return k;
}

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int root = 0;
		vector<int> b(n);//ancestor array
		vector<vector<int>> g(n + 1);
		for (int i = 0; i < n; i++){ 
			cin >> b[i];
			if (b[i] == i + 1) root = b[i];
			else g[b[i]].pb(i + 1);
		}
		vector<int> p(n);
		for (int i = 0; i < n; i++) cin >> p[i];
		if (p[0] != root) {
	        	cout << -1 << endl;
			continue;
		}
		vector<int> vec(n + 1);
		vec[root] = 0;
		for (int i = 1; i < n; i++) {	
			vec[p[i]] = i;
		}
		if (dfs(g, root, vec)){
	        	cout << -1 << endl;
			continue;
		}
		ans[root] = 0;
		for (int i = 1; i <= n; i++) {
	        	cout << ans[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}       	