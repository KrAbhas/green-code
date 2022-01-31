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

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	char brr[3] = {'R', 'S', 'P'};
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int n = s.length();
		vector<pair<int,int>> a = {{0,0}, {0,1},{0,2}};
		for (int i = 0; i < n; i++) {
			if (s[i] == 'R') 
				a[0].first++;
			else if(s[i] == 'S')
				a[1].first++;
			else a[2].first++;
		}
		sort(all(a), greater<pi>());
		int k = a[0].first;
		for (int i = 0; i < n; i++) {
			cout << brr[(3 + a[0].second - 1) % 3];
			for (int j = 1; j < 3; j++) {
				if (a[j].first == k) {
					i++;
					if (i >= n) break;
					cout << brr[(3 + a[j].second - 1) % 3];
				}
			}
		}
		cout << endl;
	}
}       	
