#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define intl int64_t

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	int inf = (1e5 + 1);
	ll n;
	cin >> n;
	int c;
	string str;
	int k = 3 * inf;
	int p = 0;
	int arr[3];
	for (int i = 0; i < 3; i++) {
		arr[i] = 3 * inf;
	}
	vector<pair<int,string>> vec;
	for (int i = 0; i < n; i++) {
		cin >> c >> str;
		if (str.length() == 1) {
			arr[str[0] - 'A'] = min(arr[str[0] - 'A'], c);
		}
		if (str.length() == 3) {
			k = min(k, c);
			continue;
		}
		vec.push_back({c, str});
	}
	int t = vec.size();
	k = min(k, (arr[0] + arr[1] + arr[2]));
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			set<char> s;
			for (char ch : vec[i].second) {
				s.insert(ch);
			}
			for (char ch: vec[j].second) {
				s.insert(ch);
			}
			if (s.size() == 3) {
				k = min(k, vec[i].first + vec[j].first);
			}
		}
	}
	if (k == 3 * inf) {
		cout << -1 << endl;
	}
	else
		cout << k << endl;
}