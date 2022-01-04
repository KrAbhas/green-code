#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)

int main(){
	const ll inf = 1e9 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s = "aabb";
	for (int i = 0; i < n; i++) {
		cout << s[i % 4];
	}
	cout << endl;
}