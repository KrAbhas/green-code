#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n; 
	int m;
	cin >> m;
	string s;
	string t;
	cin >> s >> t;
	vector<int> left;
	vector<int>right;
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == t[j]) {
			left.pb(i);
			j++;
		}
		if (j >= m) break;
	}
	reverse(t.begin(), t.end());
	j = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == t[j]) {
			right.pb(i);
			j++;
		}
		if (j >= m) break;
	}
	reverse(right.begin(),right.end());
	int dist = 0;
	for (int i = 0; i < m - 1; i++) {
		dist = max(dist, right[i + 1] - left[i]);
	}
	cout << dist << endl;
}