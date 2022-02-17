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

int n;
int r1, c1;
int r2, c2;
vector<string> G(100);
pi pt;
int *arr;
int minm = INT_MAX;
int p, q;
vector<vector<int>> vis1(100, vector<int> (100));
vector<vector<int>> vis2(100, vector<int> (100));

void dfs2(int i, int j) {
	//cout << i << j << endl;
	vis2[i][j] = 1;
	minm = min(minm, (i - p) * (i - p) + (j - q) * (j - q));
	for (int t = 0; t < 4; t++) {
		int x = arr[t];
		int y = arr[t + 1];
		if (i - x >= 0 && j - y >= 0 && i - x < n && j - y < n && G[i - x][j - y] == '0' && !vis2[i - x][j - y])  {
			//cout << i << j << ' ' <<x << y << ' ' << i - x << j - y << ' ' << p << q << endl;
			dfs2(i - x, j - y);
		}
	}
}


void dfs(int i, int j) {
	p = i; q = j;
	vis1[i][j] = 1;
	for (int k = 0; k < n; k++) {
		for (int l = 0; l < n; l++) {
			vis2[k][l] = 0;
		}
	}
	dfs2(r2 - 1, c2 - 1);
	cout << endl;
	for (int t = 0; t < 4; t++) {
		int x = arr[t];
		int y = arr[t + 1];
		if (i - x >= 0 && j - y >= 0 && i - x < n && j - y < n && G[i - x][j - y] == '0' && vis1[i - x][j - y] == 0) {
			dfs(i - x, j - y);
		}
	}
}


int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;
	
	for (int i = 0; i < n; i++) {
		cin >> G[i];
	}
	int ar[] = {0, 1, 0, -1, 0};
	arr = ar;
	dfs(r1 - 1, c1 - 1);
	cout << minm;
}