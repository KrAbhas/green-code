#include<bits/stdc++.h>
using namespace std;

#define ll long long

int p = 1;

int issubtree;
bool traverse(vector<int> adj[], int root, int vis[], int isanc, int p, int x) {
	if (isanc && vis[root] == x) {
		//cout << root << endl;
		return true;
	}
	if(vis[root] == x && issubtree) return true;
	if (vis[root] == 0) {
		isanc = 1;
	}
	bool k = false;
	for (int v: adj[root]) {
		if (v != p) {
			k = k || traverse(adj, v, vis, isanc, root, x);
		}
	}
	if (vis[root] == x) issubtree = 1;
	return k;
}

int dfs(vector<int> adj[], int root, int x, int vis[], int arr[], int n, int p) {
	int k = arr[root];
	vis[root] = arr[root];
	for (int v: adj[root]) {
		if (v == p) 
			continue;
		else {
			int r;
			dfs(adj, v, x, vis, arr, n, root);
			vis[root] ^= vis[v];
		}
	}
	return vis[root];
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n, k;
		cin >> n >> k; 
		int arr[n + 1];
		int vis[n + 1];
		memset(vis, -1, sizeof(vis));
		int x = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			x ^= arr[i];
		}
		int u, v;
		vector<int> gr[n + 1];
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			gr[u].push_back(v);
			gr[v].push_back(u);
		}
		//cout << x << endl;

		if (x == 0) {
			cout << "YES\n";
			continue;
		}
		if (k == 2) {
			cout << "NO\n";
			continue;
		}
		issubtree = 0;
		p = 2;
		vis[1] = arr[1];
		dfs(gr, 1, x, vis, arr, n, 0);
		if(traverse(gr, 1, vis, 0, 0, x)) {
			p = 0;
			cout << "YES\n";
		}
		if (p != 0) {
			cout << "NO\n";
		}
	}
}